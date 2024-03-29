#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


int check(int n,char cuvant[], int stare_actuala,int stari_fin[],int lung,int mat[][30])
{
    int q[n*n+1];
    int st=1,dr=1;
    q[st]=stare_actuala;
    int poz_crt;
    int poz_cuv=0;
    int l=strlen(cuvant)-1;
    while(st<=dr && poz_cuv<=l)
    {
        poz_crt=q[st];
        int val=cuvant[poz_cuv]-'a';
        poz_cuv++;
        for(int i=1;i<=n;i++)
        {
            if(mat[poz_crt][i]==val)
            {
                dr++;
                q[dr]=i;
            }
        }
        st++;
    }
    if(st<=dr)
    {
        for(int i=st;i<=dr;i++)
        {
            for(int j=1;j<=lung;j++)
            {
                if(q[i]==stari_fin[j])
                    return 1;
            }
        }
    }
    return 0;


}

int main()
{
    int n,x,y,m,nr1,nr2,s,nrf;
    char l;
    fin>>n;
    int v[n+1];
    for(int i=1;i<=n;i++)
        fin>>v[i];
    fin>>m;
    int mat[n+1][30]={-1};
    for(int i=1;i<=m;i++){
        fin>>x>>y>>l;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==x)nr1=i;
            if(v[i]==y)nr2=i;
        }
        mat[nr1][nr2]=l-'a';
    }
    int stare_init;
    fin>>s;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==s)
            stare_init=i;
    }
    fin>>nrf;
    int stari_fin[nrf+1];
    int cnt=1;
    int stare;
    for(int i=1;i<=nrf;i++)
    {
        fin>>stare;
        for(int j=1;j<=n;j++)
        {
            if(v[j]==stare)
                stari_fin[cnt++]=j;
        }
    }
    cnt--;
    int nrCuv;
    char cuvant[256];
    fin>>nrCuv;
    for(int i=1;i<=nrCuv;i++)
    {
        fin>>cuvant;
        if(check(n,cuvant,stare_init,stari_fin,cnt,mat)==1)
            fout<<"DA\n";
        else
            fout<<"NU\n";
    }
    return 0;
}
