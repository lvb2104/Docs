#include <bits/stdc++.h>

class Book
{
    private:
        std::string publisherName;
        int publishYear;
};

class StudyBook : public Book
{
    private:
        std::string subject;
};

class TextBook : public Book
{
    private:
        std::string school;
};

class PracticeBook : public Book
{
    private:
        std::string levelOfDifficulty;
};

int main()
{
    
    return 0;
}