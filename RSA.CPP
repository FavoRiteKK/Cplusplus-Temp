#include"stdio.h"
#include"conio.h"
#include"dos.h"
#include"process.h"
#include"math.h"
#include"stdlib.h"
#include"string.h"

char x[1024];   //Ban ro
int  x1[1024]; //Ban ma
int  y[1024]; //Chu ky so

int pa=0,qa=0,ea=0,da=0,na=0,olea=0;
int pb=0,qb=0,eb=0,db=0,nb=0,oleb=0;

void hidecursor(void)
{
}

void showcursor(void)
{
}

void vehcn()
{
}

void inmuc(int dong,int mau,char a[][25])
{    
}

void xuly(char flag)
{
	if (flag == 1)
		printf("Hop le.\n");
	else
		printf("Gia mao.\n");
}

void thoat()
{
	exit(0);
}

void info_chuongtrinh()
{
}

int nguyento(int n)
{
    if (n<2) {
        return 0;
    }
    else if ((n>2)&&((n%2)==0)) {
        return 0;
    }
    else
    {
        int i;
        for(i=3; i<=sqrt(n); i+=2)
            if ((n%i)==0)  return 0;
    }
    return 1;
}

int uocchung(int a,int b)
{

    if ((a==0)||(b==0)) return  (a+b);

    while(a!=b)
    {
        if (a<b) b-=a ;
        else a-=b;
    }
    return a;

}

int mod(long a,int x,int n)
{
    int d;
    d=1;

    while(x!=0)
    {
        if ((x%2)!=0) {
            d=((d*a)%n);
        }
        x=x/2;
        a=((a*a)%n);
    }
    return (d);
}

int nghichdao(int a,int m)
{
    int x1,x2,x3;
    int a1,a2,a3;
    int b1,b2,b3;
    int y2;

    x1=m;
    x2=a;
    a1=1;
    a2=0;
    b1=0;
    b2=1;
    b3=b2;
    x3=x2;

    while(x3!=1)
    {
        x3=x1%x2;
        y2=x1/x2;
        a3=a1-(a2*y2);
        b3=b1-(b2*y2);

        x1=x2;
        x2=x3;
        a1=a2;
        a2=a3;
        b1=b2;
        b2=b3;
    }

    while(b3<0) {
        b3+=m;
    }
    while(b3>m) {
        b3%=m;
    }

    return (b3);
}

void taokhoa_A(void)
{
    do
    {
        printf("----------                   TAO KHOA CHO NGUOI A                   ----------\n");
        printf("Chon p,q la so nguyen to va p khac q (3<= p,q <=180), e se tu dong sinh !\n");
		
        printf("Nhap p=");
        scanf("%d",&pa);
		
        printf("Nhap q=");
        scanf("%d",&qa);
    }
    while((nguyento(pa)==0)||(nguyento(qa)==0)||(pa==qa)||(pa<3)||(qa<3)||(pa>180)||(qa>180));

    na=pa*qa;
    olea=(pa-1)*(qa-1);
	
	printf("n=%d, ole=%d\n", na, olea);

    do
    {
        printf("Nhap e=");
        scanf("%d",&ea);
    }
    while(uocchung(ea,olea)!=1);

    da= nghichdao(ea,olea);
}

void taokhoa_B(void)
{
    do
    {
        printf("++++++++++                   TAO KHOA CHO NGUOI B                   ++++++++++\n");
		
        printf("Chon p,q la so nguyen to va p khac q (3<= p,q <=180), e se tu dong sinh !\n");
		
        printf("Nhap p=");
        scanf("%d",&pb);
		
        printf("Nhap q=");
        scanf("%d",&qb);
    }
    while((nguyento(pb)==0)||(nguyento(qb)==0)||(pb==qb)||(pb<3)||(qb<3)||(pb>180)||(qb>180));

    nb=pb*qb;
    oleb=(pb-1)*(qb-1);
	
	printf("n=%d, ole=%d\n", nb, oleb);

    do
    {
        printf("Nhap e=");
        scanf("%d",&eb);
    }
    while(uocchung(eb,oleb)!=1);

    db= nghichdao(eb,oleb);
}

int sigk(int x,int d,int n)
{
    int k;

    k= mod(x,d,n);

    return (k);
}

int verk(int x,int y,int n,int e)
{
    int test;

    test= mod(y,e,n);

    if (test==x) {
        return 1 ;
    }
    else {
        return 0;
    }
}

void ghisovaofile(int so)
{
    int i=0,k=-1;
    char kytu[10];

    if(so==0) {
        printf("%c\n", 48);
    }
    else {
        while(so>0)
        {
            k++;
            kytu[k]=(so%10)+48;
            so/=10;
        }
        for(i=k; i>=0; i--)
            printf("%c", kytu[i]);
    }
	
}

void ghitep(char x[1024],int y[1024],int p,int q,int n,int e,int d)
{
    FILE *file1;
    int i,k;

    k= strlen(x);
	
    {
        printf("Khoa bi mat d=");
        ghisovaofile(d);
		
        printf("\nChu ky so: ");

        for(i=0; i<k; i++)
        {
            ghisovaofile(y[i]);
            if (i<(k-1))
				printf(" ");
        }


        printf("\n=================================\n");
    }
}

void ghitep1(int x1[1024],int y[1024],int na,int nb)
{
    int i,k;

    k= strlen(x);

    if (0) {
        printf("LOI KHOI TAO FILE !");
    }
    else
    {
        if (na<nb) {
            printf("Chuong trinh su dung phuong phap ** KY TRUOC <-> MA SAU **");
            printf("\n\n\n");
        }
        else  {
            printf("Chuong trinh su dung phuong phap ** MA TRUOC <-> KY SAU **");
            printf("\n\n\n");
        }

        printf("\nKhoa bi mat cua nguoi A la d_A = ");
        ghisovaofile(da);
		printf("\n");

        printf("\nKhoa bi mat cua nguoi B la d_B = ");
        ghisovaofile(db);
		printf("\n");


        printf("\nBan tin ma hoa A --> B: ");

        for(i=0; i<k; i++)
        {
            ghisovaofile(x1[i]);
            if (i<(k-1))
				printf(" ");
        }

        printf("\n\n\n");

        printf("Chu ky so ma hoa A--> B: ");

        for(i=0; i<k; i++)
        {
            ghisovaofile(y[i]);
            if (i<(k-1))
				printf(" ");
        }

        printf("\n==================================\n");
    }
}

void giai_ma_noi_dung(char x[1024], int y[1024])
{
    int k,i;

    printf("Noi dung ban ro: ");
    k=strlen(x);
    for(i=0; i<k; i++)
		printf("%c",x[i]);
		
    printf("\n\n\r Chu ky so tuong ung:");
    for(i=0; i<k; i++)
		printf(" %d",y[i]);
}

void kytruocmasau(void)
{
    int i;

    fflush(stdin);

    printf("Nhap ban tin de nguoi A --> B :");
    gets(x);

    for(i=0; i<strlen(x); i++)  //tao chu ky truoc
        y[i]=sigk(x[i],da,na);

    for(i=0; i<strlen(x); i++) // ma hoa ban tin x va chu ky y
    {
        x1[i]=mod(x[i],eb,nb);
        y[i]=mod(y[i],eb,nb);
    }

    ghitep1(x1,y,na,nb);

}

void matruockysau(void)
{
    int i;

    fflush(stdin);

    printf("Nhap ban tin de nguoi A --> B :");
    gets(x);

    for(i=0; i<strlen(x); i++) // ma hoa ban tin x truoc
    {
        x1[i]=mod(x[i],eb,nb);
    }


    for(i=0; i<strlen(x); i++)  // ky len ban ma sau khi ma hoa
        y[i]=sigk(x1[i],da,na);

    ghitep1(x1,y,na,nb); //gui ban tin cho B sau khi ma hoa

}

void kytruoc_masau(void)
{
    FILE *file_ma;
    FILE *file_ky;

    char path_ma[255];
    char path_ky[255];
    char ch;
    char flag=1;

    int i=-1,j=0,k=-1,t=-1;
    int so=0;
    int chisox1,chisoy;

    printf("                             CHI TIET VUA NHAP !");
    printf("\n\n\r  Khoa cong khai cua nguoi A la (n,e)= %d, %d",na,ea);
    printf("\n\r  Khoa bi mat cua nguoi A la d = %d",da);

    printf("\n\r  Khoa cong khai cua nguoi B la (n,e)= %d, %d",nb,eb);
    printf("\n\r  Khoa bi mat cua nguoi B la d = %d",db);

    printf("\n\n\r  Vi (Na<Nb) nen phai ma hoa theo quy tac : KY TRUOC-MA SAU !");

    fflush(stdin);
    printf("\n\n\r  Nhap vao duong dan den file chua ban ma: ");
    gets(path_ma);
    fflush(stdin);
    printf("\n  Nhap vao duong dan den file chua ma chu ky: ");
    gets(path_ky);

    if (( (file_ma= fopen(path_ma,"r"))==NULL )||( (file_ky= fopen(path_ky,"r"))==NULL )) {
        printf("\n\n\r  Duong dan ban vua nhap khong ton tai, vui long nhap lai !");
    }
    else
    {
        while( (ch =fgetc(file_ma))!=EOF )  i++;
        if (i==-1) {
            printf("\n\n\r  File chua ban ma khong co du lieu !");
            return;
        }
        else
        {
            file_ma= fopen(path_ma,"r");
            while (j<=i+1) //Doc ky tu tu file roi chuyen thanh so luu vao mang X1
            {
                ch= fgetc(file_ma);
                if ((ch==32)||(ch==13)||(ch==10)||(j==i+1)) {
                    t++;
                    j++;
                    x1[t]=so;
                    so=0;
                }
                else {
                    so= (so*10)+(ch-48);
                    j++;
                }
            }
        }
        chisox1=t;


        j=0;
        t=-1;// khoi tao lai gia tri ban dau

        while( (ch =fgetc(file_ky))!=EOF )  k++;
        if (k==-1) {
            printf("\n\n\r  File chua ma chu ky khong co du lieu !");
             return;
        }
        else
        {
            file_ky= fopen(path_ky,"r");
            while (j<=k+1) //Doc ky tu tu file roi chuyen thanh so luu vao mang Y
            {
                ch= fgetc(file_ky);
                if ((ch==32)||(ch==13)||(ch==10)||(j==k+1)) {
                    t++;
                    j++;
                    y[t]=so;
                    so=0;
                }
                else {
                    so= (so*10)+(ch-48);
                    j++;
                }
            }

        }
        chisoy=t;

        if(chisox1!=chisoy) {
            xuly(0);
        }
        else
        {
            for(i=0; i<=chisox1; i++) //Giai ma
            {
                x[i]=mod(x1[i],db,nb);
                y[i]=mod(y[i],db,nb);
            }

            for(i=0; i<=chisox1; i++) // Kiem tra chu ky
                if (verk(x[i],y[i],na,ea)!=1) {
                    flag=0;
                    break ;
                }

            if (flag) {
                xuly(1);
                giai_ma_noi_dung(x,y);
            }
            else xuly(0);
        }
    }

}

void matruoc_kysau(void)
{
    FILE *file_ma;
    FILE *file_ky;

    char path_ma[255];
    char path_ky[255];
    char ch;
    char flag=1;

    int i=-1,j=0,k=-1,t=-1;
    int so=0;
    int chisox1,chisoy;

    printf("                             CHI TIET VUA NHAP !");
    printf("\n\n\r  Khoa cong khai cua nguoi A la (n,e)= %d, %d",na,ea);
    printf("\n\r  Khoa bi mat cua nguoi A la d = %d",da);

    printf("\n\r  Khoa cong khai cua nguoi B la (n,e)= %d, %d",nb,eb);
    printf("\n\r  Khoa bi mat cua nguoi B la d = %d",db);

    printf("\n\n\r  Vi (Na>Nb) nen phai ma hoa theo quy tac : MA TRUOC-KY SAU !");

    fflush(stdin);
    printf("\n\n\r  Nhap vao duong dan den file chua ban ma: ");
    gets(path_ma);
    fflush(stdin);
    printf("\n  Nhap vao duong dan den file chua ma chu ky: ");
    gets(path_ky);

    if (( (file_ma= fopen(path_ma,"r"))==NULL )||( (file_ky= fopen(path_ky,"r"))==NULL )) {
        printf("\n\n\r  Duong dan ban vua nhap khong ton tai, vui long nhap lai !");
    }
    else
    {
        while( (ch =fgetc(file_ma))!=EOF )  i++;
        if (i==-1) {
            printf("\n\n\r  File chua ban ma khong co du lieu !");
            return;
        }
        else
        {
            file_ma= fopen(path_ma,"r");
            while (j<=i+1) //Doc ky tu tu file ma roi chuyen thanh so luu vao mang X1
            {
                ch= fgetc(file_ma);
                if ((ch==32)||(ch==13)||(ch==10)||(j==i+1)) {
                    t++;
                    j++;
                    x1[t]=so;
                    so=0;
                }
                else {
                    so= (so*10)+(ch-48);
                    j++;
                }
            }
        }
        chisox1=t;


        j=0;
        t=-1;// khoi tao lai gia tri ban dau

        while( (ch =fgetc(file_ky))!=EOF )  k++;
        if (k==-1) {
            printf("\n\n\r  File chua ma chu ky khong co du lieu !");
            return;
        }
        else
        {
            file_ky= fopen(path_ky,"r");
            while (j<=k+1) //Doc ky tu tu file chu ky roi chuyen thanh so luu vao mang Y
            {
                ch= fgetc(file_ky);
                if ((ch==32)||(ch==13)||(ch==10)||(j==k+1)) {
                    t++;
                    j++;
                    y[t]=so;
                    so=0;
                }
                else {
                    so= (so*10)+(ch-48);
                    j++;
                }
            }

        }
        chisoy=t;

        if(chisox1!=chisoy) {
            xuly(0);
        }
        else
        {
            for(i=0; i<=chisox1; i++) // Kiem tra chu ky
                if (verk(x1[i],y[i],na,ea)!=1) {
                    flag=0;
                    break ;
                }

            if (flag) {
                xuly(1);
                for(i=0; i<=chisox1; i++) //Giai ma
                    x[i]=mod(x1[i],db,nb);
                giai_ma_noi_dung(x,y);
            }
            else xuly(0);
        }
    }

thoat:
    return;
}

void taochukydacbiet(void)
{
    showcursor();

    taokhoa_A();
    fflush(stdin);

    taokhoa_B();
    fflush(stdin);

    if (na<=nb) {
        kytruocmasau();
    }
    else {
        matruockysau();
    }

    hidecursor();
}

void kiemtrachukydacbiet(void)
{
    showcursor();

    printf("----------               NHAP KHOA CUA NGUOI NGUOI A                ----------");
	
    printf("Nhap n= ");
    scanf("%d",&na);
	
    printf("Nhap e= ");
    scanf("%d",&ea);
	
    printf("Nhap khoa bi mat d= ");
    scanf("%d",&da);

    printf("++++++++++               NHAP KHOA CUA NGUOI NGUOI B                ++++++++++");
	
    printf("Nhap n= ");
    scanf("%d",&nb);
	
    printf("Nhap e= ");
    scanf("%d",&eb);
	
    printf("Nhap khoa bi mat d= ");
    scanf("%d",&db);

    if (na<=nb) {
        kytruoc_masau();
    }
    else {
        matruoc_kysau();
    }

    hidecursor();
}

void taochukythuong(void)
{
    int i,k;

    showcursor();
    taokhoa_A();

    fflush(stdin);

    printf("Nhap xau de tao chu ky :");
    gets(x);

    k= strlen(x);

    for(i=0; i<k; i++)
        y[i]= sigk(x[i],da,na);

    ghitep(x,y,pa,qa,na,ea,da);

}

void kiemtrachukythuong(void)
{
	int j = strlen(x), k = 0;
	int n = na, e = olea;
	char flag = -1;
                    for (k=0; k<=j; k++)
                        if ((verk(x[k],y[k],n,e)!=1)) {
                            flag=0;
                            break ;
                        }

                    if (flag) {
                        xuly(1);
                        giai_ma_noi_dung(x,y);
                    }
                    else {
                        xuly(0);
                    }
}

int  main(void)
{
	do
	{
		int choice = 0;
		printf("1. Tao chu ky thuong.\n");
		printf("2. Kiemm tra chu ky thuong.\n");
		printf("3. Tao chu ky dac biet.\n");
		printf("4. Kiemm tra chu ky dac biet.\n");
		
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:	taochukythuong();	break;
			case 2: kiemtrachukythuong(); break;
			
			case 3:	taochukydacbiet();	break;
			case 4: kiemtrachukydacbiet(); break;
			default: thoat();
		}
	}
	while (true);
	return 0;
}