#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char* const xml_part =
    "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
const char* const opening_landscape_a4_svg =
    "<svg width=\"297mm\" height=\"210mm\" viewBox=\"0 0 297 210\" "
    "version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
const char* const closing_svg =
    "</svg>";


void Koch_points(FILE* ofile, int i, double x0, double y0, double x4, double y4)
{
    if (i == 0)
    {
        fprintf(ofile,
            " %lf, %lf %lf, %lf\n",
            x0, y0, x4, y4);
        return;
    }
    double x1 = x0 + (x4 - x0)/3;
    double y1 = y0 + (y4- y0)/3;
    double x3 = x0 + 2*(x4 - x0)/3;
    double y3 = y0 + 2*(y4 - y0)/3;
    double x2 = (x3 - x1)*cos(M_PI/3) + (y3 - y1)*sin(M_PI/3) + x1;
    double y2 = -(x3 - x1)*sin(M_PI/3) + (y3 - y1)*cos(M_PI/3)+ y1;

    Koch_points(ofile, i-1, x0, y0, x1, y1);
    Koch_points(ofile, i-1, x1, y1, x2, y2);
    Koch_points(ofile, i-1, x2, y2, x3, y3);
    Koch_points(ofile, i-1, x3, y3, x4, y4);
}

void example_content(FILE* ofile)
{
    fprintf(ofile, "<polyline stroke=\"blue\" fill=\"none\" points=\"\n");
    Koch_points(ofile, 4, 20, 72, 200, 72);
    fprintf(ofile, "\"/>");
}

void hello(FILE* ofile)
{
    fprintf(ofile, "Hello world!");
}

void write_to_file(const char* filename, void script(FILE*))
{
    FILE* ofile = fopen(filename, "w");
    script(ofile);
    fclose(ofile);
}

void write_a4_mm_svg(FILE* ofile, void write_content(FILE*))
{
    fprintf(ofile, "%s\n", xml_part);
    fprintf(ofile, "%s\n", opening_landscape_a4_svg);
    write_content(ofile);
    fprintf(ofile, "%s\n", closing_svg);
}

void example_script(FILE* ofile)
{
    write_a4_mm_svg(ofile, example_content);
}

void example1()
{
    write_to_file("example1.svg", example_script);
}

int main ()
{
    const char* filename = "test.txt";
    const char* wzorek = "wzorek.svg";
    write_to_file(filename, hello);
    write_to_file(wzorek, example_content);
    example1();
}
