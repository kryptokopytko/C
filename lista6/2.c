#include <stdio.h>
#include <string.h>

const char* print_line(const char* str)
{
    printf("%s\n", str);
    return str;
}

char* end_of_strcpy(char* dst, const char* src)
{
    int l = 0;
    while(dst[l] != '\0')
    {
        *(dst+l) = *(src+l);
        l++;
    }
    return &dst[l];
}

void print_lines(int argcc, const char* argv[])
{
    for (int i = 0; i < argcc; i++)
        print_line(argv[i]);
}

int sum_strlen(int argc, const char* argv[])
{
    int s = 0;
    for (int i = 0; i < argc; i++)
        s += strlen(argv[i]);
    return s;
}

int main ()
{
    const char* str = "-_-";
    char dst[] = "ZAREZERWOWANE";
    const char* src = "OuO";
    const char* argv[] = {"aa", "bb", "cc"};
    int argc = 0;
    while (argv[argc] != '\0')
        argc++;
    print_lines(argc, argv);
    printf("%d", sum_strlen(argc, argv));
    end_of_strcpy(dst, src);
    printf("%s", dst);
}
