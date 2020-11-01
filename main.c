#include <stdio.h>
#include <stdlib.h>


typedef struct draw
{
    int aa;
    int date[3];
    int numbers[5];
    int joker;
}draw[1986];

void compare (int **a,int x)
{
    int i,k,t,temp;
    for (i=1;i<x;i++)
    {
        for (k=(x-1);k>0;k--)
        {
            if (a[k][1]>a[k-1][1])
            {
                temp=a[k][1];
                a[k][1]=a[k-1][1];
                a[k-1][1]=temp;
                t=a[k][0];
                a[k][0]=a[k-1][0];
                a[k-1][0]=t;

            }
        }
    }
}

void com (float **a,int x)
{
    int i,k,t,temp;
    for (i=1;i<x;i++)
    {
        for (k=(x-1);k>0;k--)
        {
            if (a[k][1]>a[k-1][1])
            {
                temp=a[k][1];
                a[k][1]=a[k-1][1];
                a[k-1][1]=temp;
                t=a[k][0];
                a[k][0]=a[k-1][0];
                a[k-1][0]=t;

            }
        }
    }
}



int main()
{
    draw d;
    FILE *fp;
    float pw,**p,**pj,*f,*fj,w1,w2,*del,*deljo;
    int abbb,choice,k=0,a,i,b0,b1,b2,ch,c,w,chan=0,sum=0,**ad,arc=0,*arcp;
    if ((fp=fopen("joker.csv","r"))==NULL)
    {
        printf ("The file could not be found!");
        exit(2);
    }
    else
    {
        while (!feof(fp))
        {
            fscanf (fp,"%d;",&d[k].aa);
            fscanf (fp,"%d/%d/%d",&d[k].date[0],&d[k].date[1],&d[k].date[2]);
            fscanf (fp,";%d;%d;%d;%d;%d;",&d[k].numbers[0],&d[k].numbers[1],&d[k].numbers[2],&d[k].numbers[3],&d[k].numbers[4]);
            fscanf (fp,"%d",&d[k].joker);
            k++;
        }
    }
    fclose(fp);
    printf ("Enter your choice!\n");
    printf(" 1. Search a draw\n 2. Display the frequency of the numbers and the joker numbers\n 3. Display delay appearance of the numbers and the joker numbers\n 4. Suggestion to play\n 0. Exit\n");
    scanf("%d",&choice);
    while (choice!=0)
    {
        if (choice==1)
        {
            printf ("Search a draw!\nEnter your choice\n 1. Serial Number\n 2. Date\n 3. Number\n 4. Joker Number\n 0. Exit searching\n\n");
            scanf("%d",&ch);
            while (ch!=0)
            {
                if (ch==1)
                {
                printf ("Enter the serial number (from -218 to 1767): ");
                scanf("%d",&a);
                if (a< (-218) || a>1767)
                    {
                        printf("The number you gave is incorrect!\n");

                        while (a< (-218) || a>1767)
                        {
                            printf("Please try again: ");
                            scanf("%d",&a);
                        }
                    }
                for (i=0;i<1986;i++)
                {
                    if (d[i].aa==a)
                    {
                        printf("Match found!\n Serial number: %d\n Date: %d/%d/%d\n Numbers: %d %d %d %d %d\n Joker: %d\n\n",d[i].aa,d[i].date[0],d[i].date[1],d[i].date[2],d[i].numbers[0],d[i].numbers[1],d[i].numbers[2],d[i].numbers[3],d[i].numbers[4],d[i].joker);
                        printf("Enter your choice!\n 1. Edit the serial number\n 2. Delete the serial number\n 0. No changes\n");
                        scanf("%d",&ch);
                        if (ch==1)
                        {
                            chan=1;
                            printf("Enter the serial number you want to overwrite: \n");
                            scanf("%d",&c);
                            d[i].aa=c;
                        }
                        if (ch==2)
                        {
                            chan=1;
                            d[i].aa='d';
                        }
                    }
                }
                if (chan==1)
                {
                    printf("Enter your choice!\n 1. Save the changes on the file\n 0. Do not save the changes on the file\n");
                    scanf("%d",&c);
                    if (c==1)
                    {
                        if ((fp=fopen("joker.csv","w"))==NULL)
                        {
                            printf ("The file could not be found!");
                            exit(2);
                        }
                    else
                    {
                        for (i=0;i<1986;i++)
                        {
                            if (d[i].aa!='d')
                            {
                                fprintf(fp,"%d;",d[i].aa);
                            }
                            for (k=0;k<2;k++)
                            {
                                if (d[i].date[k]!='d')
                                {
                                    fprintf(fp,"%d/",d[i].date[k]);
                                }
                            }
                            if (d[i].date[2]!='d')
                            {
                                fprintf(fp,"%d;",d[i].date[2]);
                            }
                            for (k=0;k<5;k++)
                            {
                            if (d[i].numbers[k]!='d')
                                {
                                    fprintf(fp,"%d;",d[i].numbers[k]);
                                }
                            }
                            if (d[i].joker!='d')
                            {
                                fprintf(fp,"%d\n",d[i].joker);
                            }
                        }
                    }
                }
            }
            }
            if (ch==2)
            {
                printf ("Enter the date (e.g. 16/6/1987). Please try years from 1997 to 2016: ");
                scanf("%d/%d/%d",&b0,&b1,&b2);
                if ((b0<1 || b0>31) || (b1<1 || b1>12) || (b2<1997 || b2>2016))
                {
                    printf("The date you gave is incorrect!\n");
                }
                while ((b0<1 || b0>31) || (b1<1 || b1>12) || (b2<1997 || b2>2016))
                {
                    printf("Please try again: ");
                    scanf("%d/%d/%d",&b0,&b1,&b2);

                }
                for (i=0;i<1986;i++)
                {
                    if (d[i].date[0]==b0 && d[i].date[1]==b1 && d[i].date[2]==b2)
                    {
                        printf("Match found!\n Serial number: %d\n Date: %d/%d/%d\n Numbers: %d %d %d %d %d\n Joker: %d\n\n",d[i].aa,d[i].date[0],d[i].date[1],d[i].date[2],d[i].numbers[0],d[i].numbers[1],d[i].numbers[2],d[i].numbers[3],d[i].numbers[4],d[i].joker);
                        printf("Enter your choice!\n 1. Edit the serial number\n 2. Delete the serial number\n 0. No changes\n");
                        scanf("%d",&ch);
                        if (ch==1)
                        {
                            chan=1;
                            printf("Enter the date you want to overwrite: \n");
                            scanf("%d/%d/%d",&c,&a,&w);
                            d[i].date[0]=c;
                            d[i].date[1]=a;
                            d[i].date[2]=w;
                        }
                        if (ch==2)
                        {
                            chan=1;
                            d[i].date[0]='d';
                            d[i].date[1]='d';
                            d[i].date[2]='d';
                        }
                    }
                    else
                    {
                        sum=1;
                    }
                }
                if (sum==1)
                {
                    printf("No draw on this date\n\n");
                }
                if (chan==1)
                {
                    printf("Enter your choice!\n 1. Save the changes on the file\n 0. Do not save the changes on the file\n");
                    scanf("%d",&c);
                    if (c==1)
                    {
                        if ((fp=fopen("joker.csv","w"))==NULL)
                        {
                            printf ("The file could not be found!");
                            exit(2);
                        }
                        else
                        {
                            for (i=0;i<1986;i++)
                            {
                                if (d[i].aa!='d')
                                {
                                    fprintf(fp,"%d;",d[i].aa);
                                }
                                for (k=0;k<2;k++)
                                {
                                    if (d[i].date[k]!='d')
                                    {
                                        fprintf(fp,"%d/",d[i].date[k]);
                                    }
                                }
                                if (d[i].date[2]!='d')
                                {
                                    fprintf(fp,"%d;",d[i].date[2]);
                                }
                                for (k=0;k<5;k++)
                                {
                                    if (d[i].numbers[k]!='d')
                                    {
                                        fprintf(fp,"%d;",d[i].numbers[k]);
                                    }
                                }
                                if (d[i].joker!='d')
                                {
                                    fprintf(fp,"%d\n",d[i].joker);
                                }
                            }
                        }
                    }
                }
            }
            if (ch==3)
            {
                arc=0;
                printf ("Enter the number (from 1 to 45): ");
                scanf("%d",&a);
                if (a<1 || a>45)
                    printf("The number  you gave is incorrect!\n");
                while (a<1 || a>45)
                {
                    printf("Please try again:");
                    scanf("%d",&a);
                }
                for (i=0;i<1986;i++)
                {
                    if (d[i].numbers[0]==a || d[i].numbers[1]==a || d[i].numbers[2]==a || d[i].numbers[3]==a || d[i].numbers[4]==a)
                    {
                        arc++;
                        printf("Match found!\n %d \nSerial number: %d\n Date: %d/%d/%d\n Numbers: %d %d %d %d %d\n Joker: %d\n\n",arc,d[i].aa,d[i].date[0],d[i].date[1],d[i].date[2],d[i].numbers[0],d[i].numbers[1],d[i].numbers[2],d[i].numbers[3],d[i].numbers[4],d[i].joker);
                        if (arc==1)
                        {
                            arcp=calloc(1,sizeof(int));
                            if (arcp==NULL)
                            {
                                puts ("Insufficient memory!");
                                exit(2);
                            }
                        }
                        else
                            arcp=realloc(arcp,arc*sizeof(int));
                        arcp[arc-1]=i;
                    }
                }
                printf("Enter your choice!\n 1. Edit a serial number\n 2. Delete a serial number\n 0. No changes\n");
                        scanf("%d",&ch);
                        if (ch==1)
                        {
                            chan=1;
                            printf ("Enter which draw you want to edit: ");
                            scanf("%d",&abbb);
                            printf("Enter the number you want to overwrite: \n");
                            scanf("%d",&c);
                            i=arcp[abbb-1];
                            for(w=0;w<5;w++)
                            {
                                if (d[i].numbers[w]==a)
                                d[i].numbers[w]=c;
                            }
                        }
                        if (ch==2)
                        {
                            chan=1;
                            printf ("Enter which draw you want to delete: ");
                            scanf("%d",&abbb);
                            i=arcp[abbb-1];
                            for(w=0;w<5;w++)
                            {
                                if (d[i].numbers[w]==a)
                                d[i].numbers[w]='d';
                            }
                        }
                }
                if (chan==1)
                {
                    printf("Enter your choice!\n 1. Save the changes on the file\n 0. Do not save the changes on the file\n");
                    scanf("%d",&c);
                    if (c==1)
                    {
                        if ((fp=fopen("joker.csv","w"))==NULL)
                        {
                            printf ("The file could not be found!");
                            exit(2);
                        }
                        else
                        {
                            for (i=0;i<1986;i++)
                            {
                                if (d[i].aa!='d')
                                {
                                    fprintf(fp,"%d;",d[i].aa);
                                }
                                for (k=0;k<2;k++)
                                {
                                    if (d[i].date[k]!='d')
                                    {
                                        fprintf(fp,"%d/",d[i].date[k]);
                                    }
                                }
                                if (d[i].date[2]!='d')
                                {
                                    fprintf(fp,"%d;",d[i].date[2]);
                                }
                                for (k=0;k<5;k++)
                                {
                                    if (d[i].numbers[k]!='d')
                                    {
                                        fprintf(fp,"%d;",d[i].numbers[k]);
                                    }
                                }
                                if (d[i].joker!='d')
                                {
                                    fprintf(fp,"%d\n",d[i].joker);
                                }
                            }
                        }
                    }
                }
            }
            if (ch==4)
            {
                arc=0;
                printf ("Enter the Joker number (from 1 to 20): ");
                scanf("%d",&a);
                if (a<1 || a>20)
                    printf("The date you gave is incorrect!\n");
                while (a<1 || a>20)
                {
                    printf("Please try again:");
                    scanf("%d",&a);
                }
                for (i=0;i<1986;i++)
                {
                    if (d[i].joker==a)
                    {
                        arc++;
                        printf("Match found!\n Serial number: %d\n Date: %d/%d/%d\n Numbers: %d %d %d %d %d\n Joker: %d\n\n",d[i].aa,d[i].date[0],d[i].date[1],d[i].date[2],d[i].numbers[0],d[i].numbers[1],d[i].numbers[2],d[i].numbers[3],d[i].numbers[4],d[i].joker);
                        if (arc==1)
                        {
                            arcp=calloc(1,sizeof(int));
                                if (arcp==NULL)
                                {
                                    puts ("Insufficient memory!");
                                    exit(2);
                                }
                        }
                        else
                            arcp=realloc(arcp,arc*sizeof(int));
                        arcp[arc-1]=i;
                    }
                }
                printf("Enter your choice!\n 1. Edit the serial number\n 2. Delete the serial number\n 0. No changes\n");
                scanf("%d",&ch);
                if (ch==1)
                {
                    chan=1;
                    printf ("Enter which draw you want to edit: ");
                    scanf("%d",&abbb);
                    printf("Enter the joker number you want to overwrite: \n");
                    scanf("%d",&c);
                    i=arcp[abbb-1];
                    d[i].joker=c;
                }
                if (ch==2)
                {
                    chan=1;
                    printf ("Enter which draw you want to delete: ");
                    scanf("%d",&abbb);
                    i=arcp[abbb-1];
                    d[i].joker='d';
                }
                  if (chan==1)
                {
                    printf("Enter your choice!\n 1. Save the changes on the file\n 0. Do not save the changes on the file\n");
                    scanf("%d",&c);
                    if (c==1)
                    {
                        if ((fp=fopen("joker.csv","w"))==NULL)
                        {
                            printf ("The file could not be found!");
                            exit(2);
                        }
                        else
                        {
                            for (i=0;i<1986;i++)
                            {
                                if (d[i].aa!='d')
                                {
                                    fprintf(fp,"%d;",d[i].aa);
                                }
                                for (k=0;k<2;k++)
                                {
                                    if (d[i].date[k]!='d')
                                    {
                                        fprintf(fp,"%d/",d[i].date[k]);
                                    }
                                }
                                if (d[i].date[2]!='d')
                                {
                                    fprintf(fp,"%d;",d[i].date[2]);
                                }
                                for (k=0;k<5;k++)
                                {
                                    if (d[i].numbers[k]!='d')
                                    {
                                        fprintf(fp,"%d;",d[i].numbers[k]);
                                    }
                                }
                                if (d[i].joker!='d')
                                {
                                    fprintf(fp,"%d\n",d[i].joker);
                                }
                            }
                        }
                    }
                }
            }
            printf ("Search a draw!\nEnter your choice\n 1. Serial Number\n 2. Date\n 3. Number\n 4. Joker Number\n 0. Exit searching\n\n");
            scanf("%d",&ch);
        }
        else if (choice==2)
        {
            ad=calloc(20,sizeof(int*));
            if (ad==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }
            for (k=0;k<20;k++)
            {
                ad[k]=calloc(2,sizeof(int));
                if (ad[k]==NULL)
                {
                    puts("Insufficient memory!");
                    exit(2);
                }
            }
            for (k=1;k<21;k++)
            {
                ad[k-1][0]=k;
                ad[k-1][1]=0;
                for (i=0;i<1986;i++)
                {
                    if (d[i].joker==k)
                    {
                        ad[k-1][1]++;
                    }
                }
            }
            compare(ad,20);
            printf("The frequency of the Joker numbers:\n\n");
            for (k=0;k<20;k++)
            {
                pw=ad[k][1];
                pw=100*pw/1986;
                printf("Joker %d: %d times %2.2f percent\n",ad[k][0],ad[k][1],pw);
            }
            for (k=0;k<2;k++)
            {
                free(ad[k]);
            }
            free(ad);
            ad=calloc(45,sizeof(int*));
            if (ad==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }
            for (k=0;k<45;k++)
            {
                ad[k]=calloc(2,sizeof(int));
                if (ad[k]==NULL)
                {
                    puts("Insufficient memory!");
                    exit(2);
                }
            }
            for (k=1;k<46;k++)
            {
                ad[k-1][0]=k;
                ad[k-1][1]=0;
                for (i=0;i<1986;i++)
                {
                    if (d[i].numbers[0]==k || d[i].numbers[1]==k || d[i].numbers[2]==k || d[i].numbers[3]==k || d[i].numbers[4]==k)
                    {
                        ad[k-1][1]++;
                    }
                }
            }
            printf ("\n");
            compare(ad,45);
            printf("The frequency of the Numbers:\n\n");
            for (k=0;k<45;k++)
            {
                pw=ad[k][1];
                pw=100*pw/1986;
                printf("Number %d: %d times %2.2f percent\n",ad[k][0],ad[k][1],pw);
            }
            for (k=0;k<2;k++)
            {
                free(ad[k]);
            }
            free(ad);
        }
        else if (choice==3)
        {
            ad=calloc(45,sizeof(int*));
            if (ad==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }
            for (k=0;k<45;k++)
            {
                ad[k]=calloc(2,sizeof(int));
                if (ad[k]==NULL)
                {
                    puts("Insufficient memory!");
                    exit(2);
                }
            }
            for (i=0;i<45;i++)
            {
                ad[i][0]=i+1;
                ad[i][1]=0;
                for (k=0;k<1986;k++)
                {
                    if ((i+1)==d[k].numbers[0] ||(i+1)==d[k].numbers[1] ||(i+1)==d[k].numbers[2] ||(i+1)==d[k].numbers[3] ||(i+1)==d[k].numbers[4])
                    {
                       ad[i][1]=0;
                    }
                    else
                    {
                        ad[i][1]++;
                    }
                }
            }
            compare(ad,45);
            printf("The delay appearance of the numbers is: \n\n");
            for (i=0;i<45;i++)
            {
                printf("Number %d: %d\n",ad[i][0],ad[i][1]);
            }
            for (k=0;k<2;k++)
            {
                free(ad[k]);
            }
            free(ad);
            ad=calloc(20,sizeof(int*));
            if (ad==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }
            for (k=0;k<20;k++)
            {
                ad[k]=calloc(2,sizeof(int));
                if (ad[k]==NULL)
                {
                    puts("Insufficient memory!");
                    exit(2);
                }
            }

            for (i=0;i<20;i++)
            {
                ad[i][0]=i+1;
                ad[i][1]=0;
                for (k=0;k<1986;k++)
                {
                    if ((i+1)==d[k].joker)
                    {
                        ad[i][1]=0;
                    }
                    else
                    {
                        ad[i][1]++;
                    }
                }
            }
            compare(ad,20);
            printf("The delay appearance of the Joker numbers is: \n\n");
            for (i=0;i<20;i++)
            {
                printf("Joker %d: %d\n",ad[i][0],ad[i][1]);
            }
            for (k=0;k<2;k++)
            {
                free(ad[k]);
            }
            free(ad);
     }
        else if (choice==4)
        {
            fj=calloc(20,sizeof(float*));
            if (fj==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }

            for (k=0;k<20;k++)
            {
                fj[k]=0;
            }
            for (k=1;k<21;k++)
            {
                for (i=0;i<1986;i++)
                {
                    if (d[i].joker==k)
                    {
                        fj[k-1]++;
                    }
                }
            }
            for (k=0;k<20;k++)
            {
                pw=fj[k];
                pw=100*w/1986;
                fj[k]=pw;
            }
            f=calloc(45,sizeof(float*));
            if (f==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }

            for (k=0;k<45;k++)
            {
                f[k]=0;
            }
            for (k=1;k<46;k++)
            {
                for (i=0;i<1986;i++)
                {
                    if (d[i].numbers[0]==k || d[i].numbers[1]==k || d[i].numbers[2]==k || d[i].numbers[3]==k || d[i].numbers[4]==k)
                    {
                        f[k-1]++;
                    }
                }
            }
            for (k=0;k<45;k++)
            {
                pw=f[k];
                pw=100*w/1986;
                f[k]=pw;
            }
            del=calloc(45,sizeof(float));
            if (del==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }
            for (i=0;i<45;i++)
            {
                del[i]=0;
                for (k=0;k<1986;k++)
                {
                    if ((i+1)==d[k].numbers[0] ||(i+1)==d[k].numbers[1] ||(i+1)==d[k].numbers[2] ||(i+1)==d[k].numbers[3] ||(i+1)==d[k].numbers[4])
                    {
                        del[i]=0;
                    }
                    else
                    {
                        del[i]++;
                    }
                }
            }
            deljo=calloc(20,sizeof(float));
            if (deljo==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }
            for (i=0;i<20;i++)
            {
                deljo[i]=0;
                for (k=0;k<1986;k++)
                {
                    if ((i+1)==d[k].joker)
                    {
                        deljo[i]=0;
                    }
                    else
                    {
                        deljo[0]++;
                    }
                }
            }
            for (i=0;i<45;i++)
            {
                pw=del[i];
                pw=100*pw/1986;
                del[i]=pw;
            }
            for (i=0;i<20;i++)
            {
                pw=deljo[i];
                pw=100*pw/1986;
                deljo[i]=pw;
            }
            printf("Enter the the weight of the frequency: ");
            scanf("%f",&w1);
            w2=1-w1;
            p=calloc(45,sizeof(float*));
            if (p==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }
            for (k=0;k<45;k++)
            {
                p[k]=calloc(2,sizeof(float));
                if (p[k]==NULL)
                {
                    puts("Insufficient memory!");
                    exit(2);
                }
            }
            for (i=0;i<45;i++)
            {
                p[i][0]=i+1;
                p[i][1]=(f[i]*w1)+(del[i]*w2);
            }
            pj=calloc(20,sizeof(float*));
            if (pj==NULL)
            {
                puts("Insufficient memory!");
                exit(2);
            }
            for (k=0;k<20;k++)
            {
                pj[k]=calloc(2,sizeof(float));
                if (pj[k]==NULL)
                {
                    puts("Insufficient memory!");
                    exit(2);
                }
            }
            for (i=0;i<20;i++)
            {
                pj[i][0]=i+1;
                pj[i][1]=(fj[i]*w1)+(deljo[i]*w2);
            }
            com(p,45);
            com(pj,20);
            printf("Enter how many numbers you will play (from 5 to 45): ");
            scanf("%d",&a);
            printf("Enter how many joker numbers you will play (from 1 to 20): ");
            scanf("%d",&ch);
            printf("The numbers we recommend: \n");
            for (i=0;i<a;i++)
            {
                printf("%2.0f ",p[i][0]);
            }
            printf("\n");
            printf("The Joker numbers we recommend: \n");
            for (i=0;i<ch;i++)
            {
                printf("%2.0f ",pj[i][0]);
            }
            printf("\n");
            free (p);
            free (pj);
            free (del);
            free (deljo);
            free (f);
            free (fj);
        }
        printf ("Enter your choice!\n");
        printf("1. Search a draw\n2. Display the frequency of the numbers and the joker numbers\n3. Display delay appearance of the numbers and the joker numbers\n4. Suggestion to play\n0. Exit\n");
        scanf("%d",&choice);
        }
    return 0;
}
