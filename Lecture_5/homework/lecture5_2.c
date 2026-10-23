#include<stdio.h>
#include<math.h>
float distance(float point[2], float line[3]);

int main(){
    float point[2]={1,5}, line[3]={2, 6, 8}, d;
    d = distance(point, line);
    printf("The distance between the point (%.1f, %.1f) and the line %.0fx + %.0fy + %.0f = 0 is: %f units\n", point[0], point[1], line[0], line[1], line[2], d);
    return 0;
}

float distance(float point[2], float line[3]){
    float d;
    d = fabs((line[0]*point[0]+line[1]*point[1]+line[2])/(sqrt(line[0]*line[0]+line[1]*line[1])));
    return d;
}