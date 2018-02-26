//纯粹想法题。。想之前需要有反演的知识，给你一个大圆的半径，一个小圆的半径，一个数k，小圆与大圆相切，再放一个圆与小圆大圆均相切，
//然后接着放圆，从此时计数，问第k大的半径是多少。
//从绿色圆开始计数，
//反演知识是，圆关于边上一点反演后是直线，圆关于圆外或者圆内一点反演后还是圆，以最左边的点进行反演，大圆和小圆得到了两条直线 x=1/(2R),x=1/(2r);
//其余圆反演后夹在这两条直线中间，并且大小相等，坐标为（（R+r）/(4Rr),  k*(R-r)/(2Rr)）;之后再反演回去得到原来的圆的半径
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    double R,r,k;
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%lf%lf%lf",&R,&r,&k);
        //printf("%lf %lf %lf\n",R,r,k);
        double a=(R+r)/(4*R*r),b=k*(R-r)/(2*R*r);
        double t=(R-r)/(4*R*r);
        //printf("%lf %lf %lf\n",a,b,k);
        double s=t/(a*a+b*b-t*t);
        printf("%.9lf\n",s);
    }
    return 0;
}
//参考http://blog.csdn.net/gh546okmy/article/details/41652373
