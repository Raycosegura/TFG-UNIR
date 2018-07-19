//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
        TGroupBox *GroupBox5;
        TButton *Button1;
        TButton *Button2;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label1;
        TLabel *Label2;
        TGroupBox *GroupBox3;
        TLabel *Label10;
        TCheckBox *CheckBox5;
        TGroupBox *GroupBox1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TCheckBox *CheckBox1;
        TUpDown *UpDown1;
        TCheckBox *CheckBox2;
        TUpDown *UpDown2;
        TGroupBox *GroupBox2;
        TLabel *Label7;
        TLabel *Label8;
        TCheckBox *CheckBox3;
        TUpDown *UpDown3;
        TEdit *Edit3;
        TPopupMenu *PopupMenu1;
        TMainMenu *MainMenu;
        TMenuItem *Archivo1;
        TMenuItem *Ayuda;
        TMenuItem *N1;
        TMenuItem *ABOUT;
        TMenuItem *Salir;
    void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
    void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
    void __fastcall UpDown3Click(TObject *Sender, TUDBtnType Button);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
       // void __fastcall Button3Click(TObject *Sender);
       // void __fastcall Button4Click(TObject *Sender);
        void __fastcall SalirClick(TObject *Sender);
        void __fastcall ABOUTClick(TObject *Sender);
       // void __fastcall Transposicinporfilas1Click(TObject *Sender);
       // void __fastcall Transposicinporcolumnas1Click(TObject *Sender);
       // void __fastcall Transposicinporfilasautomtico1Click(
         // TObject *Sender);
      //  void __fastcall Transposicinporcolumnasautomtico1Click(
      //    TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
      //  void __fastcall Presentacin1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
