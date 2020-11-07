#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int const MAX = 512;

int const smax = 40;

struct Img
{
    int nl;
    int nc;
    int dados[MAX][MAX][3];
};

void abre_img(char nome[], Img& img);

void salva_img(char nome[],Img img);

void binariza(Img img, Img& img_out, int n);

void reflete_hori(Img img_in, Img& img_out);

void corta_rgb(Img img_in, Img& img_out, int li, int ci, int lf, int cf);

void borra_imagem(Img img_in, Img& img_out);


int main()
{
    int escolha,n, ci,li,cf,lf, tela=0;
    bool veri=false;
    int choice;
    Img img_in;
    Img img_out;
    char nome[smax];

    while(true)
    {
        if(tela==0)
        {
            cout<<" ______________________________________________"<<endl;
            cout<<"|         << EDITOR DE FOTOS (BETA) >>         |"<<endl;
            cout<<"|                                              |"<<endl;
            cout<<"| 1- Binarizar                  2-Refletir     |"<<endl;
            cout<<"|                                              |"<<endl;
            cout<<"| 3- Cortar                     4-Borrar       |"<<endl;
            cout<<"|                                              |"<<endl;
            cout<<"| 5- Salvar                     6-Sair         |"<<endl;
            cout<<"|                                              |"<<endl;
            cout<<"|______________________________________________|"<<endl;
            cout<<" Powered By: Lia & Raffa                        \n"<<endl;
            cout<<endl;
            cout<<">>";
            cin>>escolha;
            do
            {
                if(escolha<1||escolha>6)
                {
                    cout<<"Insira um valor valido"<<endl;
                    cin>>escolha;
                }
            }
            while(escolha<1||escolha>6);
            tela=1;
        }

        if(tela==1)
        {
            if(escolha==1)
            {
                cin.ignore();
                if(veri==false)
                {
                    cout<<"Insira o nome do arquivo para ser aberto"<<endl;
                    cout<<">>";
                    cin.getline(nome,smax);
                    abre_img(nome,img_in);
                    system("cls");
                    cout<<" ______________________________________________"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                 BINARIZANDO                  |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|           Insira o limiar da foto:           |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|______________________________________________|"<<endl;
                    cout<<endl;
                    cout<<">>";
                    cin>>n;
                    binariza(img_in, img_out, n);
                    veri=true;
                    tela = 2;
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    cout<<" ______________________________________________"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                 BINARIZANDO                  |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|           Insira o limiar da foto:           |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|______________________________________________|"<<endl;
                    cout<<endl;
                    cout<<">>";
                    cin>>n;
                    binariza(img_out, img_out, n);
                    veri=true;
                    tela = 2;
                    system("pause");
                    system("cls");
                }
            }
            if(escolha==2)
            {
                cin.ignore();
                if(veri==false)
                {
                    cout<<"Insira o nome do arquivo para ser aberto"<<endl;
                    cout<<">>";
                    cin.getline(nome,smax);
                    abre_img(nome,img_in);
                    system("cls");
                    cout<<" ______________________________________________"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                 REFLETINDO                   |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|______________________________________________|"<<endl;
                    reflete_hori(img_in,img_out);
                    veri=true;
                    tela=2;
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    cout<<" ______________________________________________"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                 REFLETINDO                   |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|______________________________________________|"<<endl;
                    reflete_hori(img_out,img_out);
                    veri=true;
                    tela=2;
                    system("pause");
                    system("cls");
                }
            }
            if(escolha==3 )
            {
                cin.ignore();
                if(veri==false)
                {
                    cout<<"Insira o nome do arquivo para ser aberto"<<endl;
                    cout<<">>";
                    cin.getline(nome,smax);
                    abre_img(nome,img_in);
                    system("cls");
                    cout<<" ______________________________________________"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                  CORTANDO                    |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|______________________________________________|"<<endl;
                    cout<<"Insira os valores da linha inicial e linha final e da coluna inicial e final"<<endl;
                    cin>>li>>lf>>ci>>cf;
                    do
                    {
                        if(li<0||li>img_in.nl)
                        {
                            cout<<"Insira um valor valido para a linha"<<endl;
                        }
                    }
                    while(li<0||li>img_in.nl);

                    do
                    {
                        if(lf<0||lf>img_in.nl)
                        {
                            cout<<"Insira um valor valido para a linha final"<<endl;
                        }
                    }
                    while(lf<0||lf>img_in.nl);

                    do
                    {
                        if(ci<0||ci>img_in.nc)
                        {
                            cout<<"Insira um valor valido para a coluna"<<endl;
                        }
                    }
                    while(ci<0||ci>img_in.nc);

                    do
                    {
                        if(cf<0||cf>img_in.nc)
                        {
                            cout<<"Insira um valor valido para a linha"<<endl;
                        }
                    }
                    while(cf<0||cf>img_in.nc);

                    corta_rgb(img_in, img_out,li,ci,lf,cf);
                    veri=true;
                    tela=2;
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    cout<<" ______________________________________________"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                  CORTANDO                    |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|______________________________________________|"<<endl;
                    cout<<"Insira os valores da linha inicial e linha final e da coluna inicial e final"<<endl;
                    cin>>li>>lf>>ci>>cf;
                    do
                    {
                        if(li<0||li>img_out.nl)
                        {
                            cout<<"Insira um valor valido para a linha"<<endl;
                        }
                    }
                    while(li<0||li>img_out.nl);

                    do
                    {
                        if(lf<0||lf>img_out.nl)
                        {
                            cout<<"Insira um valor valido para a linha final"<<endl;
                        }
                    }
                    while(lf<0||lf>img_out.nl);

                    do
                    {
                        if(ci<0||ci>img_out.nc)
                        {
                            cout<<"Insira um valor valido para a coluna"<<endl;
                        }
                    }
                    while(ci<0||ci>img_out.nc);

                    do
                    {
                        if(cf<0||cf>img_out.nc)
                        {
                            cout<<"Insira um valor valido para a linha"<<endl;
                        }
                    }
                    while(cf<0||cf>img_out.nc);

                    corta_rgb(img_out, img_out,li,ci,lf,cf);
                    veri=true;
                    tela=2;
                    system("pause");
                    system("cls");
                }
            }
            if(escolha==4)
            {
                cin.ignore();
                if(veri==false)
                {
                    cout<<"Insira o nome do arquivo para ser aberto"<<endl;
                    cout<<">>";
                    cin.getline(nome,smax);
                    abre_img(nome,img_in);
                    system("cls");
                    cout<<" ______________________________________________"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                  BORRANDO                    |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|______________________________________________|"<<endl;
                    borra_imagem(img_in,img_out);
                    veri=true;
                    tela=2;
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    cout<<" ______________________________________________"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|                  BORRANDO                    |"<<endl;
                    cout<<"|                                              |"<<endl;
                    cout<<"|______________________________________________|"<<endl;
                    borra_imagem(img_out,img_out);
                    veri=true;
                    tela=2;
                    system("pause");
                    system("cls");
                }
            }
            if(escolha==5)
            {

                if(veri==false)
                {
                    cout<<"Voce deveria ter escolhido uma foto para editar primeiro"<<endl;
                    tela=0;
                }
                system("pause");
                system("cls");
            }
            if(escolha==6)
            {
                exit(0);

            }
        }
        if(tela==2)
        {
            cout<<" ______________________________________________"<<endl;
            cout<<"|                                              |"<<endl;
            cout<<"|              Voce deseja:                    |"<<endl;
            cout<<"|                                              |"<<endl;
            cout<<"|              1 - Salvar a foto.              |"<<endl;
            cout<<"|              2 - Continuar Editando.         |"<<endl;
            cout<<"|              3 - Editar uma nova foto.       |"<<endl;
            cout<<"|                                              |"<<endl;
            cout<<"|______________________________________________|"<<endl;
            cout<<endl;
            cout<<">>";
            cin>>choice;
            if(choice==1)
            {
                cin.ignore();
                cout<<"Insira o nome do arquivo para ser salvo"<<endl;
                cin.getline(nome,smax);
                salva_img(nome,img_out);
                cout<<"Salvo com sucesso";
                cout<<endl;
                system("pause");
                tela=0;
                veri=false;
                system("cls");
            }
            else if(choice==2)
            {
                tela=0;
                veri=true;
                system("cls");
            }
            else if(choice==3)
            {
                tela=0;
                veri=false;
                system("cls");
            }
        }
    }
}



void abre_img(char nome[], Img& img)
{
    int np,i,j,z;
    char ppm[] = "P3", formarq[smax],formato[]=".ppm";
    fstream arq;
    arq.open(strcat(nome,formato));

    if(!arq.is_open())
    {
        cout<<"Arquivo não encontrado"<<endl;
        exit(0);
    }
    else
    {
        cout<<"Arquivo aberto"<<endl;
    }

    arq.getline(formarq,smax);

    if(strcmp(ppm,formarq)!=0)
    {
        cout<<"Formato de Arquivo Incorreto"<<endl;
        exit(0);
    }

    arq>>img.nc>>img.nl;
    arq>> np;

    for(int i=0; i<img.nl; i++)
    {
        for(int j=0; j<img.nc; j++)
        {
            for(int z=0; z<3; z++)
            {
                arq>> img.dados[i][j][z];
            }
        }
    }


}

void salva_img(char nome[],Img img)
{
    ofstream arq;
    char ppm[]="P3", formato[]=".ppm";
    int i,j,z;
    arq.open(strcat(nome,formato));

    arq<<ppm<<endl;
    arq<<img.nc<<" "<<img.nl<<endl;
    arq<<255<<endl;
    for(int i=0; i<img.nl; i++)
    {
        for(int j=0; j<img.nc; j++)
        {
            for(int z=0; z<3; z++)
            {
                arq<<img.dados[i][j][z]<<" ";
            }
        }
        arq<<endl;
    }

    arq.close();

}

void binariza(Img img, Img& img_out, int n)
{
    int media;
    img_out.nl=img.nl;
    img_out.nc=img.nc;
    for(int i=0; i<img.nl; i++)
    {
        for(int j=0; j<img.nc; j++)
        {
            float somatoria=0.0;
            for(int k=0; k<3; k++)
            {
                somatoria += img.dados[i][j][k];
            }
            media = somatoria/3;
            for(int k=0; k<3; k++)
            {
                if(media>=n)
                {
                    img_out.dados[i][j][k]=255;
                }
                else
                {
                    img_out.dados[i][j][k]=0;
                }
            }
        }
    }
}

void reflete_hori(Img img_in, Img& img_out)
{
    img_out.nl=img_in.nl;
    img_out.nc=img_in.nc;
    int aux_j = img_in.nc-1;

    for(int i=0; i<img_in.nl; i++)
    {
        for(int j=0; j<img_in.nc/2; j++)
        {
            for(int z=0; z<3; z++)
            {
                img_out.dados[i][j][z] = img_in.dados[i][j][z];
            }
        }
    }

    for(int i=0; i<img_in.nl; i++)
    {
        for(int j=img_in.nc/2; j<img_in.nc; j++)
        {
            for(int z=0; z<3; z++)
            {
                img_out.dados[i][j][z] = img_in.dados[i][aux_j-j][z];
            }
        }
    }


}

void corta_rgb(Img img_in, Img& img_out, int li, int ci, int lf, int cf)
{
    img_out.nl=(lf-li)+1;
    img_out.nc=(cf-ci)+1;
    for(int i=0; i<img_out.nl; i++)
    {
        for(int j=0; j<img_out.nc; j++)
        {
            for(int z=0; z<3; z++)
            {
                img_out.dados[i][j][z] = img_in.dados[li+i][ci+j][z];
            }
        }
    }

}
void borra_imagem(Img img_in, Img& img_out)
{
    img_out.nl=img_in.nl;
    img_out.nc=img_in.nc;

    int m=3;

    int filtro[m][m];

    for(int i = 0; i< m; i++)
    {
        for(int j = 0; j< m; j++)
        {
            filtro[i][j] = 1;
        }
    }

    for(int i = 0; i < img_in.nl; i++)
    {
        for(int j = 0; j < img_in.nc; j++)
        {
            int R = 0, G = 0, B = 0;
            for(int p = 0; p < 3; p++)
            {
                for(int q = 0; q < 3; q++)
                {
                    if(i+p-1 >=0 && j+q-1 >=0 && i+p-1<img_in.nl && j+q-1<img_in.nc)
                    {
                        R += img_in.dados[i+p-1][j+q-1][0]*filtro[p][q];
                        G += img_in.dados[i+p-1][j+q-1][1]*filtro[p][q];
                        B += img_in.dados[i+p-1][j+q-1][2]*filtro[p][q];
                    }
                }
            }
            img_out.dados[i][j][0] = R/9;
            img_out.dados[i][j][1] = G/9;
            img_out.dados[i][j][2] = B/9;
        }
    }
}
