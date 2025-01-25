#include<stdio.h>
#include<math.h>


void chandu()
{
    printf("\nPress Q to quit the program.");
    printf("\nIf You Want to Add Old Credit Press Y or don't then press N.  \n\nPlease enter Y or N : ");
}

double mad(double cgpa)
{
    int i,n;
    double a[100],b[100],bom=0,rock[100],cradit=0;
    printf("\nEnter Your Total Subject : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nWrite The Credit of %d Subject : ",i+1);
        scanf("%lf",&a[i]);
        printf("\nWrite The GPA of %d Subject : ",i+1);
        scanf("%lf",&b[i]);
        cradit=cradit+a[i];
        rock[i]=a[i] * b[i];
        bom = bom + rock[i];
    }

    cgpa = bom/cradit;

    return cgpa;
}

double kalu(double wow)
{
    int i,n;
    double a[100],b[100],c,d,m,cradit=0,bom=0,cgpa,rock[100];
    printf("\nEnter Your Total Credit You earned : ");
    scanf("%lf",&c);
    printf("\nEnter Your Total CGPA You earned : ");
    scanf("%lf",&d);
    printf("\nEnter Your Total Subject : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nWrite The Credit of %d Subject : ",i+1);
        scanf("%lf",&a[i]);
        printf("\nWrite The GPA of %d Subject : ",i+1);
        scanf("%lf",&b[i]);
        cradit=cradit+a[i];
        rock[i]=a[i] * b[i];
        bom = bom + rock[i];
    }
    cgpa = bom/cradit;
    wow= ((cgpa * cradit) +( c*d))/(cradit+c);

    return wow;
}

int main()
{
    char z;
    int n;
    double cgpa,wow;
    for(;;)
    {
        chandu();
        scanf(" %c",&z);
        if(z== 'Y' || z== 'y')
        {
            kalu(wow);
            printf("\nYour Total CGPA IS : %.2lf",&wow);
        }
        else if(z=='N' || z=='n')
        {
            mad(cgpa);
            printf("\nYour Total CGPA IS : %.2lf",&cgpa);
        }
        else if (z=='Q' || z=='q')
        {
            printf("\nThe Program Has Been Stopped.");
            break ;
        }
        else
        {
            printf("\nYou Have Enter Wrong Key please enter Y or N or Q");
        }



    }

    return 0;
}
