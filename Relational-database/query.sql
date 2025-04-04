-- FORMER STYLE INNER JOIN = CROSS JOIN: each column in this table matches to each column in that table
SELECT *
FROM GIAOVIEN AS GV, NGUOITHAN AS NT

-- cross join
SELECT *
FROM GIAOVIEN
CROSS JOIN BOMON

-- EQUIJOIN: condition is equality
SELECT GV.MAGV, HOTEN, NT.TEN
FROM GIAOVIEN AS GV, NGUOITHAN AS NT
WHERE GV.MAGV = NT.MAGV

SELECT HOTEN, YEAR(GETDATE()) - YEAR(NGSINH) AS TUOI
FROM GIAOVIEN
WHERE YEAR(GETDATE()) - YEAR(NGSINH) > 40

SELECT COUNT(MAGV) AS SL
FROM GIAOVIEN

-- GV va GVQLCM
SELECT *
FROM GIAOVIEN AS GV1, GIAOVIEN AS GV2
WHERE GV1.GVQLCM = GV2.MAGV

-- so luong giao vien cua khoa cntt
SELECT COUNT(*)
FROM KHOA, GIAOVIEN, BOMON
WHERE KHOA.MAKHOA = BOMON.MAKHOA AND BOMON.MABM = GIAOVIEN.MABM AND KHOA.MAKHOA = 'CNTT'

-- NEW STYLE INNER JOIN
SELECT *
FROM GIAOVIEN
	JOIN BOMON ON BOMON.MABM = GIAOVIEN.MABM

-- FULL OUTER JOIN: don't match condition => null
SELECT *
FROM GIAOVIEN
	FULL OUTER JOIN BOMON
	ON BOMON.MABM = GIAOVIEN.MABM

-- left/ right join => this table in left/ right is the main table, the other is extra table

-- union
	SELECT *
	FROM GIAOVIEN
UNION
	SELECT *
	FROM NGUOITHAN

-- insert from an existing table to a new table (not exist)
SELECT MAGV
INTO NEWTABLE
FROM GIAOVIEN
SELECT *
FROM NEWTABLE

-- insert from an existing table to a new table (exist)
SELECT *
INTO CLONE_GV
FROM GIAOVIEN
WHERE 1 = 0
INSERT INTO CLONE_GV
SELECT *
FROM GIAOVIEN
SELECT *
FROM CLONE_GV

-- nested query
-- check whether a teacher '001' is a GVQLCM or not. if yes, print out
SELECT *
FROM GIAOVIEN
WHERE MAGV = '005' AND MAGV IN (
	SELECT GVQLCM
	FROM GIAOVIEN
)

SELECT *
FROM GIAOVIEN, (
	SELECT *
	FROM DETAI
) AS DT

-- print list teachers who join more than 1 topic
-- use aggregate functions
SELECT *
FROM GIAOVIEN
WHERE MAGV IN (
	SELECT MAGV
	FROM THAMGIADT
	GROUP BY MAGV
	HAVING COUNT(MADT) > 1
)

-- not use aggregate functions
SELECT *
FROM GIAOVIEN
WHERE 1 < (
	SELECT COUNT(MADT)
	FROM THAMGIADT
	WHERE MAGV = GIAOVIEN.MAGV
)

-- list info of faculties having more than 2 teachers
SELECT *
FROM KHOA AS K
WHERE 2 < (
	SELECT COUNT(GIAOVIEN.MAGV)
	FROM KHOA
	JOIN BOMON ON KHOA.MAKHOA = BOMON.MAKHOA
	JOIN GIAOVIEN ON GIAOVIEN.MABM = BOMON.MABM
	WHERE K.MAKHOA = KHOA.MAKHOA
)

-- group by thi select phai select field nam trong group by or aggregate functions (max, min, sum, avg, first, last, round, count)
-- having thi range cua no phai nam trong range cua group by thi moi su dung duoc 
-- IDENTITY(5, 10) start at 5, step 10
-- list teachers having more salary than average of salary of all teachers
SELECT *
FROM GIAOVIEN 
WHERE LUONG > (
	SELECT SUM(LUONG)
	FROM GIAOVIEN 
) / (
	SELECT COUNT(*)
	FROM GIAOVIEN 
)

SELECT GIAOVIEN.*, BOMON.TENBM
INTO NEWTABLECLONE
FROM GIAOVIEN, BOMON
SELECT *
FROM NEWTABLECLONE

-- view la bang ao, update data theo bang ma view truy van [] thay cho ''
CREATE VIEW testview AS 
SELECT * FROM GIAOVIEN

SELECT * FROM testview

-- tao index 
CREATE INDEX indexname ON GIAOVIEN (MAGV)

-- kiểu dữ liệu tự định nghĩa
-- EXEC sp_addtype 'Tên kiểu dữ liệu', 'Kiểu dữ liệu thực tế', 'not null' (có hay không đều được)
EXEC sp_addtype 'NNAME', 'NVARCHAR(100)', 'Not null' 

CREATE TABLE testtable1
(
	Name NNAME,
	Address NVARCHAR(500)
)

DROP TYPE NNAME
-- xoa type
DROP TABLE testtable1

EXEC sp_droptype 'NNAME'

-- tao ra bien va tai su dung

-- select age of teacher '001'
SELECT YEAR(GETDATE()) - YEAR(NGSINH)
FROM GIAOVIEN
WHERE MAGV = '001'

-- select ra teacher co salary cao nhat
SELECT MAGV
FROM GIAOVIEN GV
WHERE LUONG = (
--	SELECT TOP 1 LUONG
--	FROM GIAOVIEN
--	ORDER BY LUONG DESC
	SELECT MAX(LUONG)
	FROM GIAOVIEN
)

UPDATE GIAOVIEN
SET LUONG = LUONG + 1
WHERE MAGV = (
	SELECT TOP 1 MAGV
	FROM GIAOVIEN
	WHERE LUONG = (
		SELECT MIN(LUONG)
		FROM GIAOVIEN
	)
)

-- => ket hop de lay ra age cua teacher co salary cao nhat
SELECT YEAR(GETDATE()) - YEAR(NGSINH)
FROM GIAOVIEN
WHERE MAGV = (
	SELECT MAGV
	FROM GIAOVIEN GV
	WHERE LUONG = (
	--	SELECT TOP 1 LUONG
	--	FROM GIAOVIEN
	--	ORDER BY LUONG DESC
		SELECT MIN(LUONG)
		FROM GIAOVIEN
	)
)

-- cach khac ne : tao ra variable kieu char luu MAGV teacher salary thap nhat
DECLARE @MinSalaryMAGV CHAR(10)
SELECT @MinSalaryMAGV = MAGV
FROM GIAOVIEN GV
WHERE LUONG = (
	SELECT MIN(LUONG)
	FROM GIAOVIEN
)
SELECT YEAR(GETDATE()) - YEAR(NGSINH) AS AGE
FROM GIAOVIEN
WHERE MAGV = @MinSalaryMAGV
---------------------------------------------------------------------------------

-- declare
DECLARE @i INT

-- declare and assign default value
DECLARE @j INT = 0

-- assign
SET @i = @i + 1
SET @i += 1
SET @j *= @i

-- via select
DECLARE @MaxLuong int
SELECT @MaxLuong = MAX(LUONG)
FROM GIAOVIEN
SELECT @MaxLuong

-- lay ra number cua ngthan cua teacher 001

-- save MAGV
DECLARE @MAGVCanTim NCHAR(10)
SELECT @MAGVCanTim = MAGV
FROM GIAOVIEN
WHERE MAGV = '001'
-- count
DECLARE @countne INT
SELECT @countne = COUNT(*)
FROM NGUOITHAN
WHERE MAGV = @MAGVCanTim
PRINT @countne

-- lay ra luong trung binh
DECLARE @sum INT
DECLARE @slgv INT
DECLARE @kq INT
SELECT @sum = SUM(LUONG)
FROM GIAOVIEN
SELECT @slgv = COUNT(*)
FROM GIAOVIEN
SET @kq = @sum / @slgv

-- lay ra luong gv '002'
DECLARE @magvne CHAR(10) = '002'
DECLARE @luonggv INT
SELECT @luonggv = LUONG
FROM GIAOVIEN
WHERE MAGV = @magvne

PRINT @kq
PRINT @luonggv
IF (@kq > @luonggv)
BEGIN
	PRINT N'trung bình lớn hơn'
END
ELSE
BEGIN
	PRINT N'trung bình nhỏ hơn'
END


---------------------------------------------------- LOOP ----------------------------------------------------
DECLARE @i INT = 0
DECLARE @n INT = 1000
WHILE (@i < @n)
BEGIN
	PRINT @i
	SET @i += 1
END
---------------------------------------------------- CURSOR ----------------------------------------------------
-- want to traverse each record in a specific table, with each record, that'll have a different condition, we will use cursor at this point
-- declare <name of cursor> cursor for <query in here>
-- open <name of cursor>

-- fetch next from <name cursor> into <danh sach cac bien tuong ung ket qua truy van>

-- while @@FETCH_STATE = 0
-- BEGIN
-- instructions
-- FETCH NEXT one more time
-- FETCH FROM NEXT <name cursor> <danh sach cac bien tuong ung ket qua truy van>
-- END

-- CLOSE <name cursor>
-- DEALLOCATE <name cursor>

-- from age of teacher
-- if > 40 => salary = 2500
-- if 30 < and < 40 => salary = 2000
-- else => 1500

SELECT * FROM GIAOVIEN

-- analogy in c++: cursor in stack points to data in heap
DECLARE gvcursor CURSOR FOR SELECT MAGV, YEAR(GETDATE()) - YEAR(NGSINH) FROM GIAOVIEN

OPEN gvcursor

DECLARE @magv CHAR(10)
DECLARE @age INT

FETCH NEXT FROM gvcursor INTO @magv, @age

WHILE @@FETCH_STATUS = 0
BEGIN
	IF @age > 40
	BEGIN
		UPDATE GIAOVIEN SET LUONG = 2500 WHERE MAGV = @magv
	END
	ELSE IF @age > 30
	BEGIN
		UPDATE GIAOVIEN SET LUONG = 2000 WHERE MAGV = @magv
	END
	ELSE
	BEGIN
		UPDATE GIAOVIEN SET LUONG = 1500 WHERE MAGV = @magv
	END
	
	FETCH NEXT FROM gvcursor INTO @magv, @age
END

CLOSE gvcursor
DEALLOCATE gvcursor
---------------------------------------------------- STORE ----------------------------------------------------
/*
 * store PROCEDURE
 * is a program or procedure
 * we can use Transact-SQL EXECUTE (EXEC) to perform "stored procedure"
 * "stored procedure" is different from "function" about "returned value"
 * Can't be stored in "name" and used directly in "expression"
 */

/*
 * Create PROC <name>
 * [Params if have]
 * AS
 * BEGIN
 * 			<Code>
 * END
 */

CREATE PROCEDURE usp_test
@magv nchar(10), @luonggv INT
AS 
BEGIN
	SELECT * FROM GIAOVIEN WHERE MAGV = @magv AND @luonggv = LUONG
END

EXEC usp_test @magv = '', @luonggv = 0
EXEC usp_test '', 0

---------------------------------------------------- TRIGGER ----------------------------------------------------
-- Inserted: contains fields which are insert | update in table
-- Deleted: contains fields which are delete
CREATE FUNCTION uf_printname(@name nvarchar(100))
RETURNS INT
AS 
BEGIN
	PRINT @name
	RETURN 1
END


ALTER TRIGGER utg_insertgv
ON GIAOVIEN
FOR INSERT, UPDATE 
AS
BEGIN
	ROLLBACK TRAN
	PRINT 'trigger2'
END

INSERT GIAOVIEN
VALUES ('013', 'giaovienmoi', 0, 'nam', GETDATE(), 'dadfads', NULL, 'MMT')









