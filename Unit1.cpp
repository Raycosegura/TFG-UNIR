//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include <ctype>
#include "Unit1.h"
#include "Unit3.h"
#include <winbase.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString  alfa="abcdefghijklmnñopqrstuvwxyz _óé012345",alfa2="ABCDEFGHIJKLMNÑOPQRSTUVWXYZíúá@6789.,", *beto = NULL, *beto2=NULL;
char *aux = new char[37], *final = new char[37],*aux2=new char[37],*final2=new char[37];


//PROCEDIMIENTO PARA CALCULAR EL ALFABETO DE LLEGADA
void Alfabeto() {
    if (beto != NULL) {
      delete beto;
      beto = NULL;
    }

    if (beto2 != NULL){
        delete beto2;
        beto2=NULL;

    }
     //Cifrado monoalfabetico monogramico
        int a=1, b=0;
        for (int init = 0; init < 37; init++) {
          aux[init] = '.';
          aux2[init] = '.';
        }
        //Decimacion
        if (Form1->CheckBox1->State == cbChecked) {
            a=Form1->UpDown1->Position;
        }
        //Desplazamiento
        if (Form1->CheckBox2->State == cbChecked) {
            b=Form1->UpDown2->Position;
        }
        //Creacion del alfabeto decimado y desplazado
        for (int i = 0; i < 37; i++) {
            aux[i] = alfa[(((i*a)+b)%37)+1];
            aux2[i] = alfa2[(((i*a)+b)%37)+1];
        }
        //Clave
        if (Form1->CheckBox3->State == cbChecked) {
            int i = Form1->UpDown3->Position;
            int r= Form1->UpDown3->Position;
            int cont1=0;
            int cont2=0;
            for (int init = 0; init < 37; init++) {
              final[init] = '.';
              final2[init]='.';
            }
            //Inlcusion de la clave
            for (int j = 1; j <= Form1->Edit3->Text.Length(); j++) {

                if (alfa.Pos(Form1->Edit3->Text[j]) != 0) {
                    bool noexiste = true;
                    for (int k = 0; k < 37; k++) {
                        if (final[k] == Form1->Edit3->Text[j]) {
                            noexiste = false;
                            break;
                        }
                    }
                    if (noexiste) {
                        final[(i % 37)] = Form1->Edit3->Text[j];
                        i = ((i + 1) % 37);
                        cont1=1;

                    }
                }
                else
                {
                    if (alfa2.Pos(Form1->Edit3->Text[j]) != 0) {
                       bool noexiste2 = true;
                       for (int k = 0; k < 37; k++) {
                          if (final2[k] == Form1->Edit3->Text[j]) {
                            noexiste2 = false;
                            break;
                          }
                       }
                       if (noexiste2) {
                           final2[(r % 37)] = Form1->Edit3->Text[j];
                            r = ((r + 1) % 37);
                            cont2=1;
                        }
                    }
                }

            }
            //Inclusion del resto del alfabeto

            if (cont1==1)
            {
               for (int j = 0; j < 37; j++) {
                    bool noexiste = true;
                    for (int k = 0; k < 37; k++) {
                        if (final[k] == aux[j]) {
                            noexiste = false;
                            break;
                        }
                    }
                    if (noexiste) {
                        final[(i % 37)] = aux[j];
                         i = ((i + 1) % 37);
                    }
               }
                beto = new AnsiString(final);
            }
            else{

                beto = new AnsiString(aux);
            }
            
            if (cont2==1)
            {
                for (int j = 0; j < 37; j++) {
                    bool noexiste2 = true;
                    for (int k = 0; k < 37; k++) {
                        if (final2[k] == aux2[j]) {
                            noexiste2 = false;
                            break;
                        }
                    }
                    if (noexiste2) {
                        final2[(r % 37)] = aux2[j];
                         r = ((r + 1) % 37);
                    }
                }
                beto2=new AnsiString(final2);
             }
             else{

                  beto2= new AnsiString(aux2);

             }





        } else {
            beto = new AnsiString(aux);
            beto2= new AnsiString(aux2);
        }
    
}

//CIFRADO NORMAL (SIN FICHEROS, SIN MINUSCULAS)
void Cifra() {
  Alfabeto();
  int n = Form1->Edit1->Text.Length();
  char *cadena=new char[n + n/5];
  String ristra;
  int j=0;
  for (int i = 1 ; i <= n; i++) {


          if (alfa.Pos(Form1->Edit1->Text[i]) > 0) {
                   cadena[j++] = (*beto)[alfa.Pos(Form1->Edit1->Text[i])];}


          if (alfa2.Pos(Form1->Edit1->Text[i]) > 0) {
                 cadena[j++] = (*beto2)[alfa2.Pos(Form1->Edit1->Text[i])]; }

  }
    


 ristra=cadena;

 Form1->Edit2->Text = ristra.SubString(1,j);



}

//CIFRADO DE FICHEROS
void CifraFich() {
  Alfabeto();
  if (FileExists(Form1->SaveDialog1->FileName)) {
    DeleteFile(Form1->SaveDialog1->FileName);
  }
  ifstream ifs(Form1->OpenDialog1->FileName.c_str());
  ofstream ofs(Form1->SaveDialog1->FileName.c_str());
  char c;
  ifs.get(c);
  while (!ifs.eof()) {
    if (alfa.Pos(c)> 0) {
      ofs.put((*beto)[alfa.Pos(c)]);
    }
    if (alfa2.Pos(c) > 0) {

       ofs.put((*beto2)[alfa2.Pos(c)]);

     }

    if (c == '\n') {
      ofs.put('\n');

    }
    ifs.get(c);
  }
  ifs.close();
  ofs.close();
}



//DESCIFRADO NORMAL (SIN FICHEROS)
void Descifra() {
  Alfabeto();
  int n = Form1->Edit2->Text.Length();
  char *cadena = new char[n+n];
  String ristra;
  int j=0;
  for (int i = 1 ; i <= n; i++) {

         if (beto->Pos(Form1->Edit2->Text[i]) > 0) {
                cadena[j++] = alfa[beto->Pos(Form1->Edit2->Text[i])]; }


         if ( beto2->Pos(Form1->Edit2->Text[i]) > 0) {
                cadena[j++] = alfa2[beto2->Pos(Form1->Edit2->Text[i])]; }



    }


  ristra=cadena;
  Form1->Edit1->Text = ristra.SubString(1,j);


}


//DESCIFRADO DE FICHEROS
void DescifraFich() {
  Alfabeto();
  if (FileExists(Form1->SaveDialog1->FileName)) {
    DeleteFile(Form1->SaveDialog1->FileName);
  }
  ifstream ifs(Form1->OpenDialog1->FileName.c_str());
  ofstream ofs(Form1->SaveDialog1->FileName.c_str());
  char c;
  ifs.get(c);
  while (!ifs.eof()) {
    if (beto->Pos(c) > 0) {
      ofs.put(alfa[beto->Pos(c)]);
    }
    if (beto2->Pos(c)>0){

       ofs.put(alfa2[beto2->Pos(c)]);
    }
    if (c == '\n')
    {
     ofs.put('\n');
     }

    ifs.get(c);
  }
  ifs.close();
  ofs.close();
}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
Label4->Caption=UpDown1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
Label6->Caption=UpDown2->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown3Click(TObject *Sender, TUDBtnType Button)
{
Label8->Caption=UpDown3->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 
  if (CheckBox5->State == cbChecked) {
    if ((OpenDialog1->Execute())&&(SaveDialog1->Execute())) {
      Edit1->Text = OpenDialog1->FileName;
      Edit2->Text = SaveDialog1->FileName;
        CifraFich();
      }
    
  } else {

      Cifra();
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

  if (CheckBox5->State == cbChecked) {
    if ((OpenDialog1->Execute())&&(SaveDialog1->Execute())) {
      Edit1->Text = OpenDialog1->FileName;
      Edit2->Text = SaveDialog1->FileName;
       DescifraFich();
    }
  } else {
       Descifra();}


}
//---------------------------------------------------------------------------






/*void __fastcall TForm1::Button3Click(TObject *Sender)
{
   WinExec("tpf.exe", SW_NORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    WinExec("tpc.exe", SW_NORMAL);
}
//---------------------------------------------------------------------------

       */
//---------------------------------------------------------------------------

void __fastcall TForm1::SalirClick(TObject *Sender)
{
      Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ABOUTClick(TObject *Sender)
{
      Form2->ShowModal();
}
//---------------------------------------------------------------------------
 /*

void __fastcall TForm1::Transposicinporfilas1Click(TObject *Sender)
{
        WinExec("tpf.exe", SW_NORMAL);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Transposicinporcolumnas1Click(TObject *Sender)
{
        WinExec("tpc.exe", SW_NORMAL);   
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Transposicinporfilasautomtico1Click(
      TObject *Sender)
{
         WinExec("tpf(auto).exe", SW_NORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Transposicinporcolumnasautomtico1Click(
      TObject *Sender)
{
      WinExec("tpc(auto).exe", SW_NORMAL);        
}   */
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
    ShellExecute(NULL,"open",".\\MemoriaTFG.docx",NULL,NULL,SW_SHOW);
}
//---------------------------------------------------------------------------
     /*
void __fastcall TForm1::Presentacin1Click(TObject *Sender)
{
   ShellExecute(NULL,"open",".\\presentacion.ppt",NULL,NULL,SW_SHOW);         
}
//---------------------------------------------------------------------------

      */

