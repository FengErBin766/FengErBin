#include <stdio.h>
#include <stdlib.h>
typedef struct date
{
    char matter;//记录事件
    int num;//事件的编号
    int zt;//事件的处理状态，初始为零
}message;
typedef struct star//存储已处理事件
{
    char sj;
    int bh;
    int tim;//记录处理时间
}storage;
int main()
{
    int i,n,f,h,e,w;
    int x=1,y=1,z=1,t=0;
    char s;
    srand((unsigned)time(NULL));
    n=5+rand()%6;//随机生成5～10以内的数
    message a[n],d[n];
    storage b[n];
    if(n>=9)//空间不足警告
    {
        printf("          ****************************************\n");
        printf("          *                                      *\n");
        printf("          *                                      *\n");
        printf("          *   警告：                             *\n");
        printf("          *        报警序列剩余空间不足百分之十! *\n");
        printf("          *                                      *\n");
        printf("          *                                      *\n");
        printf("          ****************************************\n");
    }
    for(i=0;i<n;i++)
    {
        char c;
        c='A'+rand()%3;
        a[i].matter=c;
        d[i].matter=c;
        b[i].tim=0;
        if(c=='A')
        {
            a[i].num=x;
            d[i].num=x;
            x++;
            a[i].zt=0;
        }
        else if(c=='B')
        {
            a[i].num=y;
            d[i].num=y;
            y++;
            a[i].zt=0;
        }
        else
        {
            a[i].num=z;
            d[i].num=z;
            a[i].zt=1;
            b[t].bh=z;
            b[t].sj=c;
            z++;
            t++;
        }
    }
    int tem,k;
    char ar;
    for(i=0;i<n;i++)//给ABC 排序
    {
        for(k=0;k<n;k++)
        {
            if(a[i].matter!=a[k].matter)
            {
                if(a[i].matter<a[k].matter)
                {
                    ar=a[i].matter;
                    a[i].matter=a[k].matter;
                    a[k].matter=ar;
                    tem=a[i].num;
                    a[i].num=a[k].num;
                    a[k].num=tem;
                    tem=a[i].zt;
                    a[i].zt=a[k].zt;
                    a[k].zt=tem;
                }
            }
            else
            {
                if(a[i].num<a[k].num)
                {
                    tem=a[i].num;
                    a[i].num=a[k].num;
                    a[k].num=tem;
                    tem=a[i].zt;
                    a[i].zt=a[k].zt;
                    a[k].zt=tem;
                }
            }
        }
    }
    int m,tim,sum=0,q;
    while(1)
    {
        printf("          ****************************************\n");
        printf("          *        欢迎使用报警记录系统          *\n");
        printf("          *                                      *\n");
        printf("          *                                      *\n");
        printf("          *                                      *\n");
        printf("          *        查询全部报警信息请按1         *\n");//查询总共的报警信息
        printf("          *        查询已处理报警信息请按2       *\n");
        printf("          *        查询未处理报警信息请按3       *\n");
        printf("          *        查询报警信息请按4             *\n");
        printf("          *        处理报警信息请按5             *\n");
        printf("          *        退出请按0                     *\n");
        printf("          ****************************************\n");
        printf("\n\n\n");
        scanf("%d",&m);
        if(m==1)
        {
            printf("          ****************************************\n");
            printf("          *                                      *\n");
            printf("          *   总共报警事件：                     *\n");
            for(i=0;i<n;i++)
            {
            printf("          *                 %c%d",d[i].matter,d[i].num);
                if(d[i].matter=='A')
                {
                    printf("    紧急事件       *\n");
                }
                else if(d[i].matter=='B')
                {
                    printf("    一般事件       *\n");
                }
                else
                {
                    printf("    非紧急事件     *\n");
                }
            }
            printf("          ****************************************\n");
            continue;
        }
        if(m==2)
        {
            printf("          ********************************************************\n");
            printf("          *已处理事件：    事件类型：       花费时间：           *\n");
            printf("          *                                                      *\n");
            for(i=0;i<t;i++)
            {
                if(b[i].sj=='C')
                {
                    printf("          *            %c%d           非紧急事件        即时处理   *\n",b[i].sj,b[i].bh);
                }
                else if(b[i].sj=='B')
                {
                    printf("          *            %c%d           一般事件          %d         *\n",b[i].sj,b[i].bh,b[i].tim);
                }
                else
                {
                    printf("          *            %c%d           紧急事件          %d         *\n",b[i].sj,b[i].bh,b[i].tim);
                }
            }
            printf("          ********************************************************\n");
            continue;
        }
        if(m==3)
        {
            if(n==t)
            {
                printf("          *********************\n");
                printf("          *                   *\n");
                printf("          *   无未处理事件    *\n");
                printf("          *********************\n");
                continue;
            }
            printf("          ********************************************************\n");
            printf("          *未处理事件：    事件类型：                            *\n");
            for(i=0;i<n;i++)
            {
                if(a[i].zt==0)
                {

                   if(a[i].matter=='B')
                  {
                      printf("          *            %c%d           一般事件                     *\n",a[i].matter,a[i].num);
                  }
                  else
                  {
                      printf("          *            %c%d           紧急事件                     *\n",a[i].matter,a[i].num);
                  }
                }
            }
            printf("          ********************************************************\n");
        }
        if(m==4)
        {
            getchar();
            printf("          ****************************************\n");
            printf("          *                                      *\n");
            printf("          *   请输入查询的编号 ：");
            scanf("%c%d",&s,&e);
            printf("          ****************************************\n");
            for(i=0,w=0;i<n;i++)
            {
                if(a[i].matter==s&&a[i].num==e)
                {
                    w++;
                    printf("          ***************************************************\n");
                    printf("          *事件：          处理状态：              用时：   *\n");
                    if(a[i].matter=='C')
                    {
                         printf("          *     非紧急事件          已处理         即时处理 *\n");
                    }
                    if(a[i].zt==0)
                    {
                        if(a[i].matter=='A')
                        {
                            printf("          *     紧急事件            未处理               0  *\n");
                        }
                        else
                        {
                            printf("          *     一般事件            未处理               0  *\n");
                        }
                    }
                    else
                    {
                        for(h=0;h<t;h++)
                        {
                            if(b[h].sj==s&&b[i].bh==e)
                            {
                                if(b[h].sj=='A')
                                {
                                    printf("          *     紧急事件            已处理               %d  *\n",b[h].tim);
                                }
                                if(b[h].sj=='B')
                                {
                                    printf("          *     一般事件            已处理               %d  *\n",b[h].tim);
                                }
                                break;
                            }
                        }
                    }
                    printf("          ***************************************************\n");
                    break;
                }
            }
            if(w==0)
            {
                printf("          ********************\n");
                printf("          *                  *\n");
                printf("          *    未有此事件    *\n");
                printf("          ********************\n");
            }
            continue;
        }
        if(m==5)
        {
            if(n==t)
            {
                printf("          *************************\n");
                printf("          *                       *\n");
                printf("          * 所有警务已处理完毕！  *\n");
                printf("          *************************\n");
                continue;
            }
            printf("          ****************************************\n");
            printf("          *本次处理的事件是：                    *\n");
            for(i=0;i<n;i++)
            {
                if(a[i].zt==0)
                {
                    if(a[i].matter=='A')
                    {
                        printf("          *                  紧急事件 %c%d         *\n",a[i].matter,a[i].num);
                    }
                    else
                    {
                        printf("          *                  一般事件 %c%d         *\n",a[i].matter,a[i].num);
                    }
                    a[i].zt=1;
                    printf("          *本次处理所用时间：");
                    scanf("%d",&tim);
                    printf("          *                                      *\n");
                    printf("          ****************************************\n\n");
                    sum+=tim;
                    b[t].sj=a[i].matter;
                    b[t].bh=a[i].num;
                    b[t].tim=tim;
                    t++;
                    z++;
                    break;
                }
            }
            if(sum>=60)
            {
                for(i=0;i<n;i++)
                {
                    if(a[i].matter=='B'&&a[i].zt==0)
                    {
                        printf("          *********************************************************\n");
                        printf("          *%c%d已超一小时未处理，升级为紧急信息A%d，请及时处理。     *\n",a[i].matter,a[i].num,x);
                        printf("          *处理时间为：                                           *\n");
                        printf("          *            ");
                        scanf("%d",&tim);
                        printf("          *                                                       *\n");
                        printf("          *********************************************************\n");
                        sum+=tim;
                        a[i].matter='A';
                        a[i].num=x;
                        a[i].zt=1;
                        b[t].sj='A';
                        b[t].bh=x;
                        b[t].tim=tim;
                        t++;
                        break;
                    }
                }
            }
            if(sum>=120)//警告超时2小时未处理信息
            {
                for(i=0,q=0,k=0;i<n;i++)
                {
                    if(a[i].zt==0)
                    {
                        if(q==0)
                        {
                            printf("          *********************************************************\n");
                            printf("          *    警告！超过两小时未处理的信息：   类型：            *\n");
                            q++;
                        }
                        if(a[i].matter=='A')
                        {
                            printf("          *                                   %c%d      紧急事件    *\n",a[i].matter,a[i].num);
                            k++;
                        }
                        if(a[i].matter=='B')
                        {
                            printf("          *                                   %c%d      一般事件    *\n",a[i].matter,a[i].num);
                            k++;
                        }
                    }
                }
                if(k!=0)
                {
                    printf("          *********************************************************\n");
                }
            }
        }

        if(m==0)
            {
                printf("          *********************************************************\n");
                printf("          *                                                       *\n");
                printf("          *                     欢迎下次使用                      *\n");
                printf("          *********************************************************\n");
                break;
            }
        }
        return 0;
}
