#include <iostream>
#include <string.h>
using namespace std;
#define MAXLEN 1000

struct SNL
{
    char sign;//dau, neu so âm thì sign=-1
    char len;//chieu dài
    char num[MAXLEN];
};

void subu(SNL &r, SNL &a, SNL &b);

void InitSNL(SNL &n) //Khoi tao so nguyên lon
{
    for (int i=0; i<MAXLEN; i++) n.num[i]=0;
    n.len=0;
    n.sign=1;
}
void str2snl(char *str, SNL &n)//Chuyen mot chuoi kí tu thành so nguyên lon
{
    int i;
    if (str[0]=='-')
    {
        n.sign=-1;
        str++; //bo qua kí tu dau tiên
    }
    else
        n.sign=1;

    n.len=strlen(str);

    for (i=0; i<n.len; i++)
        n.num[i]=str[n.len-i-1]-'0';
    //n.num[i]=(int)str[i]
}

int cmpu(SNL &a, SNL &b)//So sánh 2 so nguyên lon không xét dau
{

    if (a.len>b.len)
        return 1;
    else if (a.len<b.len)
        return -1;
    else
    {
        int len=a.len-1;
        while (len>=0)
        {
            //So sánh tu chu so
            if (a.num[len]>b.num[len])
                return 1;
            else if (a.num[len]<b.num[len])
                return -1;
            else
                len--;
        }
    }
    return 0;
}

int cmp(SNL &a, SNL &b)////So sánh 2 so nguyên lon, neu a>b tra ve 1, a=b tra ve 0, a<b tra ve -1
{
    if (a.sign * b.sign<0) return a.sign;
    return a.sign * cmpu(a,b);
}

void scanSNL(SNL &n)
{
    char *t=new char[MAXLEN];
    cin>>t;
    str2snl(t,n);
    delete []t;
}

void printSNL(SNL &n)//in
{
    if (n.sign<0) cout<<"-";
    for (int i=n.len-1; i>=0; i--) cout<<(int)n.num[i];
}

void addu(SNL &s, SNL &a, SNL &b)  //cong khong xet dau
{
    InitSNL(s);
    s.len=a.len>b.len?a.len:b.len;
    char m=0;//bien nho
    for (int i=0; i<s.len; i++)
    {
        s.num[i]=a.num[i]+b.num[i]+m;
        if (s.num[i]>9)
        {
            s.num[i] -= 10;
            m=1;
        }
        else
            m=0;
    }
    if (m)
    {
        s.num[s.len]=1;
        s.len++;
    }
}

void add(SNL &s, SNL &a, SNL &b) //cong co xet dau
{
    if (a.sign*b.sign>0)
    {
        addu(s,a,b);
        s.sign=a.sign;
    }
    else
    {
        int t=cmpu(a,b);
        if (t==1)
        {
            subu(s,a,b);
            s.sign=a.sign;
        }
        else if (t==-1)
        {
            subu(s,b,a);
            s.sign=b.sign;
        }
        else
            InitSNL(s);

    }
}

void subu(SNL &r, SNL &a, SNL &b)    //tru khong xet dau
{
    InitSNL(r);
    r.len=a.len>b.len?a.len:b.len;
    int m=0;
    for (int i=0; i<r.len; i++)
    {
        if (a.num[i]<b.num[i]+m)
        {
            r.num[i]=10+a.num[i]-b.num[i]-m;
            m=1;
        }
        else
        {
            r.num[i]=a.num[i]-b.num[i]-m;
            m=0;
        }
    }
    while (r.num[r.len-1]==0) r.len--;
}

void sub(SNL &r, SNL &a, SNL &b)   //tru co xet dau
{
    b.sign=-b.sign;
    add(r,a,b);
    b.sign=-b.sign;
}

void mul(SNL &r, SNL &a, SNL &b)  //nhan hai so nguyen lon
{
    InitSNL(r);
    for (int i=0; i<b.len; i++)
        for (int j=0; j<b.num[i]; j++)
            for (int k=0; k<a.len; k++)
            {
                r.num[k+i] += a.num[k];
                if (r.num[k+i]>9)
                {
                    r.num[k+i] -= 10;
                    r.num[k+i+1]++;
                }
            }
    r.len=a.len+b.len;
    while (r.num[r.len-1]==0) r.len--;
    r.sign=a.sign*b.sign;
}

void div(SNL &r, SNL a, SNL b)  //chia 2 so nguyen lon
{
    InitSNL(r);
    r.len=a.len-b.len+1;
    if (a.len>=b.len)
    {
        int blen=b.len;
        int i;
        if (a.len>b.len)
        {
            i=a.len-1;
            int x=a.len-b.len;
            while (i>=0)
            {
                if (i>=x)
                    b.num[i]=b.num[i-x];
                else
                    b.num[i]=0;
                i--;
            }
        }
        b.len=a.len;
        SNL d;
        i=1;
        while (b.len>=blen)
        {
            while (cmpu(a,b)>-1)
            {
                subu(d,a,b);
                r.num[r.len-i]++;
                a=d;
            }
            b.len--;
            i++;
            for (int k=0; k<b.len; k++) b.num[k]=b.num[k+1];
            b.num[b.len]=0;
        }
        while (r.num[r.len-1]==0) r.len--;
    }
    r.sign=a.sign*b.sign;
}

int main()
{
    SNL a,mot,bk,c,d,two;
    InitSNL(a);
    InitSNL(mot);
    InitSNL(c);
    InitSNL(d);
    InitSNL(bk);
    InitSNL(two);
    str2snl("2",two);

    str2snl("1",mot);
    cout<<"Nhap so nguyen: ";
    scanSNL(a);
    //Tinh can bac hai cua a
    while (cmp(bk,mot))
    {
        bk=mot;
        div(c,a,mot);
        add(d,c,mot);
        div(mot,d,two);
    }
    //mot = can bac hai cua a

    mul(c,mot,mot);
    if (cmp(a,c)==0)
    {
        cout<<"So ban vua nhap la so chinh phuong cua: ";
        printSNL(mot);
    }
    else
        cout<<"NO";

    cout<<endl;
    /*system("pause");  */
    return 0;
}
