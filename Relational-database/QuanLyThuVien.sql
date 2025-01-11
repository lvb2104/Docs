CREATE DATABASE QuanLyThuVien

DROP DATABASE QuanLyThuVien

USE QuanLyThuVien

SET DATEFORMAT DMY

CREATE TABLE SACH
(
	MaSach Char(5) PRIMARY KEY,
	TenSach NVarchar(100),
	TheLoai Nvarchar(30),
	DonGia money,
	SoLuong int,
)

CREATE TABLE TACGIA
(
	MaTG Char(5) PRIMARY KEY,
	HoTen NVarchar(50),
	QuocTich NVarchar(30),
	NgaySinh Smalldatetime,
	DienThoai Varchar(15),
)

CREATE TABLE TACGIA_SACH
(
	MaTG Char(5),
	MaSach Char(5),
	PRIMARY KEY (MaTG, MaSach),
	FOREIGN KEY (MaTG) REFERENCES TACGIA (MaTG),
	FOREIGN KEY (MaSach) REFERENCES SACH (MaSach)
)

CREATE TABLE DOCGIA
(
	MaDG Char(5) PRIMARY KEY,
	TenDG NVarchar(50),
	DiaChi NVarchar(50),
	NgaySinh Smalldatetime,
	SoDienThoai Varchar(15),
	NgDK Smalldatetime,
)

CREATE TABLE PHATHANH
(
	MaPH Char(5) PRIMARY KEY,
	MaSach Char(5),
	NgayPH Smalldatetime,
	SoLuong Int,
	NXB NVarchar(100),
	LanPhatHanh Int,
	FOREIGN KEY (MaSach) REFERENCES SACH (MaSach)
)

CREATE TABLE MUONSACH
(
	MaMuon Char(5) PRIMARY KEY,
	MaDG Char(5),
	MaSach Char(5),
	NgayMuon Smalldatetime,
	NgayTra Smalldatetime,
	TrangThai NVarchar(20),
	FOREIGN KEY (MaDG) REFERENCES DOCGIA (MaDG),
	FOREIGN KEY (MaSach) REFERENCES SACH (MaSach)
)

-- Câu 2: (1.5 điểm) Thực hiện ràng buộc toàn vẹn sau: Viết trigger khi thêm hoặc cập nhật dữ liệu trong quan hệ PHATHANH phải kiểm tra ràng buộc toàn vẹn 
-- ngày phát hành sách phải lớn hơn ngày sinh của tác giả?
CREATE TRIGGER trigger_2
ON PHATHANH
FOR INSERT, UPDATE
AS
BEGIN
	IF EXISTS (
		SELECT 1
		FROM TACGIA
		JOIN TACGIA_SACH ON TACGIA.MaTG = TACGIA_SACH.MaTG
		JOIN SACH ON SACH.MaSach = TACGIA_SACH.MaSach
		JOIN inserted i ON i.MaSach = SACH.MaSach
		WHERE i.NgayPH <= TACGIA.NgaySinh
	)
	BEGIN
		RAISERROR('LOI: NGAY PHAT HANH SACH KHONG HOP LE', 16, 1)
		ROLLBACK TRANSACTION
	END
	ELSE
	BEGIN
		PRINT N'THEM DU LIEU THANH CONG'
	END
END

-- Câu 3: (0.5 điểm) Thực hiện ràng buộc toàn vẹn sau: Mỗi lần phát hành thì số lượng phải từ
-- 500 quyển trở lên?
CREATE TRIGGER trigger_3
ON PHATHANH
FOR INSERT, UPDATE
AS
BEGIN
	IF EXISTS (
		SELECT 1
		FROM inserted i
		WHERE i.SoLuong < 500
	)
	BEGIN 
		RAISERROR('BUGS!', 16, 1)
		ROLLBACK TRANSACTION
	END
	ELSE
	BEGIN 
		PRINT N'OK'
	END
	
	
END

-- Câu 4: (1.0 điểm) Cho biết thông tin độc giả (MaDG, TenDG đã mượn sách vào ngày
-- 10/12/2024?
SELECT DOCGIA.MaDG, TenDG
FROM DOCGIA
JOIN MUONSACH ON MUONSACH.MADG = DOCGIA.MADG
WHERE MUONSACH.NGAYMUON = '10/12/2024'

-- Câu 5: (1.0 điểm) Cho biết thông tin tác giả (MaTG, HoTen) viết giáo trình có tên là “Cấu
-- trúc rời rạc” do Nhà xuất bản ĐHQG-HCM phát hành?
SELECT TACGIA.MaTG, HoTen
FROM TACGIA
JOIN TACGIA_SACH ON TACGIA_SACH.MATG = TACGIA.MATG
JOIN SACH ON SACH.MASACH = TACGIA_SACH.MASACH
JOIN PHATHANH ON PHATHANH.MaSach = SACH.MaSach
WHERE SACH.TENSACH = 'Cấu trúc rời rạc' AND PHATHANH.NXB = 'ĐHQG-HCM'

-- Câu 6: (1.0 điểm) Cho biết số lượng sách của từng tác giả phát hành trong năm 2024? Thông
-- tin hiển thị bao gồm: Mã tác giả, tên tác giả và số sách đã phát hành. Sắp xếp theo số lượng giảm dần.
SELECT TACGIA.MaTG, HoTen, COUNT(PHATHANH.SoLuong) AS SoSachPhatHanh
FROM TACGIA
JOIN TACGIA_SACH ON TACGIA_SACH.MATG = TACGIA.MATG
JOIN SACH ON SACH.MASACH = TACGIA_SACH.MASACH
JOIN PHATHANH ON PHATHANH.MaSach = SACH.MaSach
WHERE YEAR(NGAYPH) = 2024
GROUP BY TACGIA.MaTG, HoTen
ORDER BY SUM(PHATHANH.SoLuong) DESC

-- Câu 7: (1.0 điểm) Tìm các độc giả mượn sách từ 3 thể loại khác nhau năm 2024.
SELECT DOCGIA.MaDG, TenDG
FROM DOCGIA
JOIN MUONSACH ON MUONSACH.MADG = DOCGIA.MADG
JOIN SACH ON SACH.MASACH = MUONSACH.MASACH
WHERE YEAR(NgayMuon) = 2024
GROUP BY DOCGIA.MaDG, TenDG
HAVING COUNT(DISTINCT TheLoai) >= 3

-- Câu 8: (1.0 điểm) Tìm nhà xuất bản (NXB) có nhiều hơn 5 loại sách được phát hành nhưng
-- chưa được mượn lần nào.
SELECT NXB
FROM PHATHANH
WHERE MASACH NOT IN (
	SELECT SACH.MASACH
	FROM SACH
	JOIN MUONSACH ON MUONSACH.MASACH = SACH.MASACH
)
GROUP BY NXB
HAVING COUNT(MASACH) > 5

-- Câu 9: (1.0 điểm) Tìm tất cả các độc giả (MaDG, TenDG) đã mượn tất cả các sách thuộc thể
-- loại “Khoa học viễn tưởng” và “Kinh tế” trong năm 2024.
SELECT MaDG, TenDG
FROM DOCGIA
WHERE NOT EXISTS (
	SELECT 1
	FROM SACH
	WHERE (TheLoai = 'Khoa học viễn tưởng' OR TheLoai = 'Kinh tế') AND NOT EXISTS (
		SELECT 1
		FROM MUONSACH
		WHERE DOCGIA.MaDG = MUONSACH.MaDG AND MUONSACH.MASACH = SACH.MASACH AND YEAR(MUONSACH.NGAYMUON) = 2024
	)
)


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


CREATE DATABASE QuanLyCuaHang

USE QuanLyCuaHang

SET DATEFORMAT DMY

CREATE TABLE KHACHHANG
(
	MAKH char(50) PRIMARY KEY,
	TENKH nvarchar(50),
	DIACHI nvarchar(50),
	LOAIKH nvarchar(50),
)

CREATE TABLE LOAICAY
(
	MALC char(50) PRIMARY KEY,
	TENLC nvarchar(50),
	XUATXU nvarchar(50),
	GIA money,
)

CREATE TABLE HOADON
(
	SOHD char(50) PRIMARY KEY,
	NGHD smalldatetime,
	MAKH char(50),
	KHUYENMAI int,
	FOREIGN KEY (MAKH) REFERENCES KHACHHANG(MAKH)
)

CREATE TABLE CTHD
(
	SOHD char(50),
	MALC char(50),
	SOLUONG int,
	FOREIGN KEY (SOHD) REFERENCES HOADON(SOHD),
	FOREIGN KEY (MALC) REFERENCES LOAICAY(MALC),
)

INSERT INTO KHACHHANG VALUES('KH01','Liz KimCuong','HaNoi','Vanglai')
INSERT INTO KHACHHANG VALUES('KH02','IvoneDieuLinh','DaNang','Thuongxuyen')
INSERT INTO KHACHHANG VALUES('KH03','EmmaNhatKhanh','TP.HCM','Vanglai')

INSERT INTO LOAICAY VALUES('LC01','Xuong rong tai tho','Mexico',180.000)
INSERT INTO LOAICAY VALUES('LC02','Sen thach ngoc','Anh',300.000)
INSERT INTO LOAICAY VALUES('LC03','Ba mau rau','Nam Phi',270.000)

INSERT INTO HOADON VALUES('1','22/11/2017','KH01',5)
INSERT INTO HOADON VALUES('2','04/12/2017','KH03',5)
INSERT INTO HOADON VALUES('3','10/12/2017','KH02',10)

INSERT INTO CTHD VALUES('1','LC01',1)
INSERT INTO CTHD VALUES('1','LC02',2)
INSERT INTO CTHD VALUES('3','LC03',5)


-- 3. Hiện thực ràng buộc toàn vẹn sau: Tất cả các mặt hàng xuất xứ từ nước Anh đều có giá lớn
-- hơn 250.000đ (1đ).
CREATE TRIGGER trigger_3
ON LOAICAY
FOR INSERT, UPDATE
AS
BEGIN
	IF EXISTS (
		SELECT 1
		FROM inserted i
		WHERE i.XUATXU = 'Anh' AND i.GIA <= 250.000 
	)
	BEGIN
		RAISERROR('BUGS', 16, 1)
		ROLLBACK TRANSACTION
	END
	ELSE
	BEGIN
		PRINT 'OK'
	END
END


-- 4. Hiện thực ràng buộc toàn vẹn sau: Hóa đơn mua với số lượng tổng cộng lớn hơn hoặc bằng
-- 5 đều được giảm giá 10 phần trăm. (2đ).
CREATE TRIGGER trigger_41
ON HOADON
FOR UPDATE
AS
BEGIN
	IF EXISTS (
		SELECT i.SOHD
		FROM inserted i
		JOIN CTHD ON CTHD.SOHD = i.SOHD
		WHERE i.KHUYENMAI < 10
		GROUP BY i.SOHD
		HAVING SUM(CTHD.SOLUONG) >= 5
	)
	BEGIN
		RAISERROR('BUGS', 16, 1)
		ROLLBACK TRANSACTION
	END
	ELSE
	BEGIN
		PRINT 'OK'
	END
END


CREATE TRIGGER trigger_42
ON CTHD
FOR INSERT, UPDATE
AS
BEGIN
	UPDATE HOADON
	SET KHUYENMAI = 10
	WHERE KHUYENMAI <> 10 AND SOHD IN (
		SELECT HOADON.SOHD
		FROM HOADON HD
		JOIN inserted ON inserted.SOHD = HD.SOHD
		GROUP BY HD.SOHD
		HAVING SUM(inserted.SOLUONG) >= 5
	)
END

-- 5. Tìm tất cả các hóa đơn có ngày lập hóa đơn trong quý 4 năm 2017, sắp xếp kết quả tăng dần
-- theo phần trăm giảm giá (1đ).
SELECT SOHD
FROM HOADON
WHERE YEAR(NGHD) = 2017 AND MONTH(NGHD) BETWEEN 9 AND 12
ORDER BY KHUYENMAI ASC

-- 6. Tìm loại cây có số lượng mua ít nhất trong tháng 12 (1đ).
SELECT TOP 1 TENLC
FROM LOAICAY
JOIN CTHD ON CTHD.MALC = LOAICAY.MALC
JOIN HOADON ON HOADON.NGHD = CTHD.SOHD
WHERE MONTH(NGHD) = 12
GROUP BY TENLC
ORDER BY SUM(SOLUONG) ASC

-- 7. Tìm loại cây mà cả khách thường xuyên (LOAIKH là ‘Thuong xuyen’) và khách vãng lai
-- (LOAIKH là ‘Vang lai’) đều mua. (1đ).
SELECT LOAICAY.MALC
FROM LOAICAY
JOIN CTHD ON CTHD.MALC = LOAICAY.MALC
JOIN HOADON ON HOADON.SOHD = CTHD.SOHD
JOIN KHACHHANG ON KHACHHANG.MAKH = HOADON.MAKH
WHERE KHACHHANG.LOAIKH = 'Thuong xuyen'
INTERSECT
SELECT LOAICAY.MALC
FROM LOAICAY
JOIN CTHD ON CTHD.MALC = LOAICAY.MALC
JOIN HOADON ON HOADON.SOHD = CTHD.SOHD
JOIN KHACHHANG ON KHACHHANG.MAKH = HOADON.MAKH
WHERE KHACHHANG.LOAIKH = 'Vang lai'

-- 8. Tìm khách hàng đã từng mua tất cả các loại cây (1đ).
SELECT MAKH
FROM HOADON
WHERE NOT EXISTS (
	SELECT 1
	FROM LOAICAY
	WHERE NOT EXISTS (
		SELECT 1
		FROM CTHD
		WHERE CTHD.MALC = LOAICAY.MALC AND HOADON.SOHD = CTHD.SOHD
	)
)
-- Tìm các MAKH trong những cái HOADON sao cho HOADON đó không tồn tại những LOAICAY mà không tồn tại trong CTHD của MAKH đó

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CREATE DATABASE QuanLyDuocPham

DROP DATABASE QuanLyDuocPham

USE QuanLyDuocPham

SET DATEFORMAT DMY

CREATE TABLE NHACUNGCAP
(
	MANCC char(50) PRIMARY KEY,
	TENNCC nvarchar(50),
	QUOCGIA nvarchar(50),
	LOAINCC nvarchar(50),
)

CREATE TABLE DUOCPHAM
(
	MADP char(50) PRIMARY KEY,
	TENDP nvarchar(50),
	LOAIDP nvarchar(50),
	GIA money,
)

CREATE TABLE PHIEUNHAP
(
	SOPN char(50) PRIMARY KEY,
	NGNHAP smalldatetime,
	MANCC char(50),
	LOAINHAP nvarchar(50),
	FOREIGN KEY (MANCC) REFERENCES NHACUNGCAP(MANCC)
)

CREATE TABLE CTPN
(
	SOPN char(50),
	MADP char(50),
	SOLUONG int,
	FOREIGN KEY (SOPN) REFERENCES PHIEUNHAP(SOPN),
	FOREIGN KEY (MADP) REFERENCES DUOCPHAM(MADP),
)

INSERT INTO NHACUNGCAP VALUES('NCC01','Phuc Hung','Viet Nam','Thuong xuyen')
INSERT INTO NHACUNGCAP VALUES('NCC02','J. B. Pharmaceuticals','India','Vang lai')
INSERT INTO NHACUNGCAP VALUES('NCC03','Sapharco','Singapore','Vang lai')

INSERT INTO DUOCPHAM VALUES('DP01','Thuoc ho PH','Siro',120.000)
INSERT INTO DUOCPHAM VALUES('DP02','Zecuf Herbal CouchRemedy','Vien nen',200.000)
INSERT INTO DUOCPHAM VALUES('DP03','Cotrim','Vien sui',80.000)

INSERT INTO PHIEUNHAP VALUES('1','22/11/2017','NCC01','Noi dia')
INSERT INTO PHIEUNHAP VALUES('2','04/12/2017','NCC03','Nhap khau')
INSERT INTO PHIEUNHAP VALUES('3','10/12/2017','NCC02','Nhap khau')

INSERT INTO CTPN VALUES('1','DP01',100)
INSERT INTO CTPN VALUES('1','DP02',200)
INSERT INTO CTPN VALUES('3','DP03',543)

-- 3. Hiện thực ràng buộc toàn vẹn sau: Tất cả các dược phẩm có loại là Siro đều có giá lớn hơn 100.000đ (1đ).
ALTER TABLE DUOCPHAM
ADD CONSTRAINT CHECK_GIA CHECK (LOAIDP <> 'Siro' OR GIA > 100.000)
-- nếu không phải siro thì auto đúng, ngược lại thì check thêm giá có lớn hơn không

-- 4. Hiện thực ràng buộc toàn vẹn sau: Phiếu nhập của những nhà cung cấp ở những quốc gia khác Việt Nam đều có loại nhập là Nhập khẩu. (2đ).
CREATE TRIGGER trigger_42
ON PHIEUNHAP
FOR INSERT, UPDATE
AS
BEGIN
	
END

-- 5. Tìm tất cả các phiếu nhập có ngày nhập trong tháng 12 năm 2017, sắp xếp kết quả tăng dần theo ngày nhập (1đ).
SELECT SOPN
FROM PHIEUNHAP
WHERE MONTH(NGNHAP) = 12 AND YEAR(NGNHAP) = 2017
ORDER BY NGNHAP ASC

-- 6. Tìm dược phẩm được nhập số lượng nhiều nhất trong năm 2017 (1đ).
SELECT TOP 1 WITH TIES DUOCPHAM.MADP
FROM DUOCPHAM
JOIN CTPN ON CTPN.MADP = DUOCPHAM.MADP
JOIN PHIEUNHAP ON PHIEUNHAP.SOPN = CTPN.SOPN
WHERE YEAR(NGNHAP) = 2017
GROUP BY DUOCPHAM.MADP
ORDER BY SUM(SOLUONG) DESC

-- 7. Tìm dược phẩm chỉ có nhà cung cấp thường xuyên (LOAINCC là Thuong xuyen) cung cấp, nhà cung cấp vãng lai (LOAINCC là Vang lai) không cung cấp. (1đ).
SELECT DUOCPHAM.MADP
FROM DUOCPHAM
JOIN CTPN ON CTPN.MADP = DUOCPHAM.MADP
JOIN PHIEUNHAP ON PHIEUNHAP.SOPN = CTPN.SOPN
JOIN NHACUNGCAP ON NHACUNGCAP.MANCC = PHIEUNHAP.MANCC
WHERE LOAINCC = 'Thuong xuyen'
EXCEPT
SELECT DUOCPHAM.MADP
FROM DUOCPHAM
JOIN CTPN ON CTPN.MADP = DUOCPHAM.MADP
JOIN PHIEUNHAP ON PHIEUNHAP.SOPN = CTPN.SOPN
JOIN NHACUNGCAP ON NHACUNGCAP.MANCC = PHIEUNHAP.MANCC
WHERE LOAINCC = 'Vang lai'

-- 8. Tìm nhà cung cấp đã từng cung cấp tất cả những dược phẩm có giá trên 100.000đ trong năm 2017 (1đ).
SELECT MANCC
FROM PHIEUNHAP
WHERE NOT EXISTS (
	SELECT 1
	FROM DUOCPHAM
	WHERE GIA > 100.000 AND YEAR(PHIEUNHAP.NGNHAP) = 2017 AND NOT EXISTS (
		SELECT 1
		FROM CTPN
		WHERE DUOCPHAM.MADP = CTPN.MADP AND PHIEUNHAP.SOPN = CTPN.SOPN
	)
)

---------------------------------------------------------------------------------
CREATE DATABASE QuanLyChanNuoi

USE QuanLyChanNuoi

SET DATEFORMAT DMY

CREATE TABLE CSCHANNUOI 
(
	MACS char(50) PRIMARY KEY,
	TENCS nvarchar(50),
	LOAICS nvarchar(50),
	NGDAIDIEN nvarchar(50),
	NGTL smalldatetime,
	DTHOAI nvarchar(50),
)

CREATE TABLE GIONGVN 
(
	MAGIONG char(50) PRIMARY KEY,
	TENGIONG nvarchar(50),
	LOAIVN nvarchar(50),
)

CREATE TABLE DIEUKIENCN 
(
	MADK char(50) PRIMARY KEY,
	MACS char(50),
	QUYMO int,
	KCXLCT int,
	KCKDC int,
	FOREIGN KEY (MACS) REFERENCES CSCHANNUOI(MACS)
)

CREATE TABLE GPCN 
(
	MAGP char(50) PRIMARY KEY,
	MACS char(50),
	NGCAP smalldatetime,
	SOGP nvarchar(50),
	SOGIONG int
	FOREIGN KEY (MACS) REFERENCES CSCHANNUOI(MACS)
)

CREATE TABLE CTGP
(
	MAGP char(50),
	MAGIONG char(50),
	SL int,
	FOREIGN KEY (MAGP) REFERENCES GPCN(MAGP),
	FOREIGN KEY (MAGIONG) REFERENCES GIONGVN(MAGIONG)
)

CREATE TABLE DOTCN
(
	MADOTCN char(50) PRIMARY KEY,
	MACS char(50),
	MAGIONG char(50),
	SLVN int,
	NGBD smalldatetime,
	PHGTHUC nvarchar(50),
	NGXUATDK smalldatetime,
	FOREIGN KEY (MACS) REFERENCES CSCHANNUOI(MACS),
	FOREIGN KEY (MAGIONG) REFERENCES GIONGVN(MAGIONG)
)

INSERT INTO CSCHANNUOI VALUES('CS001','Hoang mai','Nong ho','Nguyen Thanh Son','19/10/2019','0971507394')
INSERT INTO CSCHANNUOI VALUES('CS002','Cong ty TNHH Phung Dầu Sơn','Trang trai quy mo vua','Pham The Hung','20/10/2009','0364266792')
INSERT INTO CSCHANNUOI VALUES('CS003','Green Farm','Trang trai quy mo nho','Ho Trung Dai','15/09/2018','0356266782')

INSERT INTO GIONGVN VALUES('G001','Bo vang Viet Nam','Bo')
INSERT INTO GIONGVN VALUES('G002','Bo Bay Nui','Bo')
INSERT INTO GIONGVN VALUES('G003','De nui Ninh Binh','De')

INSERT INTO DIEUKIENCN VALUES('DK001','CS001',10,250,300)
INSERT INTO DIEUKIENCN VALUES('DK002','CS001',10,200,350)
INSERT INTO DIEUKIENCN VALUES('DK003','CS003',30,350,400)

INSERT INTO GPCN VALUES('GP001','CS001','10/10/2020','42/001/2020/DKCN',1)
INSERT INTO GPCN VALUES('GP002','CS001','08/09/2020','43/001/2020/DKCN',2)
INSERT INTO GPCN VALUES('GP003','CS002','04/06/2010','2/002/2010/DKCN',4)

INSERT INTO CTGP VALUES('GP001','G001',10)
INSERT INTO CTGP VALUES('GP002','G002',10)
INSERT INTO CTGP VALUES('GP002','G003',10)

INSERT INTO DOTCN VALUES('D001','CS001','G001',5,'15/06/2021','Tha tu do','15/05/2023')
INSERT INTO DOTCN VALUES('D002','CS001','G002',5,'15/07/2021','Tha tu do','10/05/2023')
INSERT INTO DOTCN VALUES('D003','CS003','G001',25,'20/09/2021','Tha tu do','10/03/2022')

-- 3.	Hiện thực ràng buộc toàn vẹn sau: số lượng vật nuôi từ 100 trở lên không được phép chăn nuôi theo phương thức “thả tự do” (1đ).
CREATE TRIGGER trigger_3
ON DOTCN
FOR INSERT, UPDATE
AS
BEGIN
	IF EXISTS (
		SELECT 1
		FROM inserted i
		WHERE SLVN >= 100 AND PHGTHUC = 'Tha tu do'
	)
	BEGIN
		RAISERROR('BUGS', 16, 1)
		ROLLBACK TRANSACTION
	END
	ELSE
	BEGIN
		PRINT 'OK'
	END
END

-- 4.	Hiện thực ràng buộc toàn vẹn sau: các giống của loại vật nuôi "Bo" có thời gian xuất dự kiến cách ngày bắt đầu nuôi ít nhất 12 tháng (1.5đ).
CREATE TRIGGER trigger_4
ON DOTCN
FOR INSERT, UPDATE
AS
BEGIN
	IF EXISTS (
		SELECT 1
		FROM inserted i
		JOIN GIONGVN ON GIONGVN.MAGIONG = i.MAGIONG
		WHERE GIONGVN.LOAIVN = 'Bo' AND DATEDIFF(MONTH, NGBD, NGXUATDK) < 12
	)
	BEGIN
		RAISERROR('BUGS', 16, 1)
		ROLLBACK TRANSACTION
	END
	ELSE 
	BEGIN
		PRINT 'OK'
	END
END

DROP TRIGGER trigger_4


-- 5.	Tìm các giống vật nuôi (MAGIONG, TENGIONG) thuộc loại “Bo” được chăn nuôi theo phương thức “thả tự do” dự kiến xuất trong tháng 12/2024 (1đ).
SELECT GIONGVN.MAGIONG, TENGIONG
FROM GIONGVN
JOIN DOTCN ON DOTCN.MAGIONG = GIONGVN.MAGIONG
WHERE LOAIVN = 'Bo' AND PHGTHUC = 'Tha tu do' AND MONTH(NGXUATDK) = 12 AND YEAR(NGXUATDK) = 2024

-- 6.	Tìm cơ sở chăn nuôi (MACS, TENCS) chưa có giấy phép chăn nuôi nào được cấp cho giống vật nuôi thuộc
-- loại “De” nhưng đã từng có đợt chăn nuôi các giống vật nuôi loại này trong năm 2024 (1đ).
SELECT CSCHANNUOI.MACS, TENCS
FROM CSCHANNUOI
JOIN DOTCN ON DOTCN.MACS = CSCHANNUOI.MACS
JOIN GIONGVN ON GIONGVN.MAGIONG = DOTCN.MAGIONG
WHERE LOAIVN = 'De' AND (YEAR(NGBD) <= 2024 AND 2024 <= YEAR(NGXUATDK)) AND NOT EXISTS (
	SELECT 1
	FROM GPCN
	JOIN CTGP ON CTGP.MAGP = GPCN.MAGP
	JOIN GIONGVN ON GIONGVN.MAGIONG = CTGP.MAGIONG
	WHERE GPCN.MACS = CSCHANNUOI.MACS AND LOAIVN = 'De'
)

-- 7.	Tính thời gian nuôi thực tế trung bình (theo đơn vị tháng) của từng loại vật nuôi theo từng hình thức chăn nuôi (1đ).
SELECT PHGTHUC, LOAIVN, AVG(DATEDIFF(MONTH, NGBD, NGXUATDK)) AS THOIGIANTHUC
FROM DOTCN
JOIN GIONGVN ON GIONGVN.MAGIONG = DOTCN.MAGIONG
GROUP BY PHGTHUC, LOAIVN

-- 8.	Với từng loại vật nuôi tìm giống vật nuôi(MAGIONG) từng được cấp phép với tổng số lượng nhiều nhất năm 2024 (1đ).
-- xét từng loại vật nuôi
SELECT LOAIVN, CTGP.MAGIONG
FROM CTGP
JOIN GIONGVN G ON G.MAGIONG = CTGP.MAGIONG
JOIN GPCN ON GPCN.MAGP = CTGP.MAGP
GROUP BY LOAIVN, CTGP.MAGIONG
HAVING SUM(SL) = (
	SELECT MAX(QUAN)
	FROM (
		-- tính tổng của mỗi loại giống của loại vật nuôi so với query bên ngoài
		SELECT SUM(SL) AS QUAN
		FROM CTGP
		JOIN GIONGVN ON GIONGVN.MAGIONG = CTGP.MAGIONG
		JOIN GPCN ON GPCN.MAGP = CTGP.MAGP
		WHERE G.LOAIVN = GIONGVN.LOAIVN
		GROUP BY CTGP.MAGIONG
	) NEW
)

SELECT VN.LOAIVN, VN.MAGIONG
FROM GIONGVN VN 
JOIN CTGP CT ON VN.MAGIONG=CT.MAGIONG
JOIN GPCN GP ON CT.MAGP=GP.MAGP
WHERE YEAR(GP.NGCAP)=2020
GROUP BY VN.LOAIVN, VN.MAGIONG
HAVING SUM(CT.SL)= (SELECT MAX(SUB.TONGSL)
						FROM (
							SELECT SUM(CT1.SL) TONGSL
							FROM CTGP CT1
							JOIN GIONGVN VN1 ON CT1.MAGIONG=VN1.MAGIONG
							JOIN GPCN GP1 ON CT1.MAGP=GP1.MAGP
							WHERE VN1.LOAIVN=VN.LOAIVN AND YEAR(GP1.NGCAP)=2020
							GROUP BY VN1.MAGIONG) SUB)

-- 9.	Tìm cơ sở chăn nuôi (MACS, TENCS) đã được cấp phép chăn nuôi tất cả các giống của loại vật nuôi “Bo” với số lượng mỗi giống đều từ 10 trở lên (1đ).
SELECT CSCHANNUOI.MACS, TENCS
FROM CSCHANNUOI
WHERE NOT EXISTS (
	SELECT 1
	FROM GIONGVN
	WHERE LOAIVN = 'Bo' AND NOT EXISTS (
		SELECT 1
		FROM CTGP
		JOIN GPCN ON GPCN.MAGP = CTGP.MAGP
		WHERE GIONGVN.MAGIONG = CTGP.MAGIONG AND GPCN.MACS = CSCHANNUOI.MACS AND CTGP.SL >= 10
	)
)

select cscn.MACS, cscn.TENCS
from CSCHANNUOI cscn
join DOTCN dcn on dcn.MACS=cscn.MACS
join GIONGVN gvn on gvn.MAGIONG=dcn.MAGIONG
where LOAIVN='Bo' and cscn.MACS in (
	select distinct MACS
	from GPCN
)
group by cscn.MACS, cscn.TENCS
having count(distinct dcn.MAGIONG)=(
	select count(distinct MAGIONG)
	from GIONGVN 
	where LOAIVN='Bo' 
)
intersect 
select cscn.MACS, cscn.TENCS
from CSCHANNUOI cscn
join GPCN on GPCN.MACS=cscn.MACS
join CTGP on CTGP.MAGP=GPCN.MAGP
where CTGP.SL>=10
GROUP BY cscn.MACS, cscn.TENCS
HAVING count(distinct MAGIONG)= (
	SELECT COUNT(DISTINCT MAGIONG)
	FROM CTGP 
	JOIN GPCN ON CTGP.MAGP=GPCN.MAGP
	GROUP BY MACS
)
















