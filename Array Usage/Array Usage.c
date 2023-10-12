#include <stdio.h>


int Count(int a[], int x, int m);
void Add(int a[], int c, int m);
void Enlarge (int a[], int m);
void Shrink (int b[], int m);
void Merge(int a[], int b[],int merge[],int m);
int Reduce(int merge[], int m);

int main()
{
    int a[1000],b[1000];
    int x,y,m,i,c1,c2;
    int result;
    int merge[1000];
    
    scanf("%d",&m);
    
    
   
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        //printf("%d\n",a[i]);    check
    }
     
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        //printf("%d\n",b[i]);    check
    }
    
   
    scanf("%d",&x);
    scanf("%d",&y);
   
    
    c1=Count(a,x,m);
    c2=Count(b,y,m);
    Add(a,c1,m);
    Add(b,c2,m);
    Enlarge(a,m);
    Shrink(b,m);
    Merge(a,b,merge,m);
    result=Reduce(merge,m);
    
    
    printf("%d\n",result);
    
    //printf("%d\n",c1);    check
    //printf("%d\n",c2);    check
   
   
    
    return 0;
   
}

int Count(int a[], int h, int m)
{
    int i,z=0;
    
    for (i=0;i<h;i++)
    {
        if(a[i]==a[m-i-1])
        { 
        z++;
        }
    }
    
    return z;
    
}

void Add(int a[], int c, int m)
{
    int i;
    for(i=0;i<m;i++) 
    {
    a[i]=a[i]+c;
    }
}

void Enlarge (int a[], int m)
{
    int temp[1000],i;
    
    for (i=0;i<m;i++)
    {
        temp[i]=a[i];
    }
    for (i=0;i<m;i++)
    {
        a[i]=temp[i]+temp[m-i-1];
    }   
}

void Shrink (int b[], int m)
{
     int temp[1000],i;
     
    for (i=0;i<m;i++)
    {
        temp[i]=b[i];
    }
    for (i=0;i<m;i++)
    {
        b[i]=temp[i]-temp[m-i-1];
    }   
}

void Merge(int a[], int b[],int merge[],int m)
{
    int i;
    
    for(i=0;i<m;i++)
    {
                    merge[i]=a[i]+b[i];
    }
}

int Reduce(int merge[], int m)
{
    int red=0,i;
    
    for(i=0;i<m;i++)
    {
                     red+=merge[i];
    }
    return red;
}


