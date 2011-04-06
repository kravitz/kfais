#ifndef CARD_H
#define CARD_H

#include "tableModelView.h"
#include "setting.h"

/******************************* Card (basic) *******************************/

typedef QPair<QString, QString> PairQuery;
typedef QMap<PairQuery, bool> MapQuery;

class Card: public QDialog
{
    Q_OBJECT

private:
    TableModel *tblModel;    //For update table after submit
    TblType type;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void keyPressEvent(QKeyEvent *aE);
    void closeEvent(QCloseEvent *aE);

private slots:
    void Ok();

protected:
    int id;
    QLineEdit *edtNote;

    Card(QWidget *aParent, TableModel *aModel, TblType aType, int aId);

    void CreateBasicWidgets(QLayout *aLt);

    inline void AddWid(QGridLayout *aLt, int aTblAtrI, QWidget *aW, int aRow, int aCol = 0);

    virtual bool IsValid() const;
    virtual bool Submit();

    inline bool IsNew() const;
    inline void SetRegExprInt(QLineEdit* aEdt, bool aCanBeZero = true);

    QString CreateQuary(const MapQuery &aMap);

public:
    int GetId() const;
};

/******************************* Sportsmen *******************************/

class CardSport: public Card
{
    Q_OBJECT

private:
    QVector<int> vecCoachId;
    QVector<int> vecRankId;

    QLineEdit *edtName;
    QDateEdit *edtDateBirth;
    QLineEdit *edtAddr;
    QLineEdit *edtPhone;
    QLineEdit *edtWorkplace;
    QLineEdit *edtJob;
    QLineEdit *edtRegNum;
    QComboBox *cbRank;
    QComboBox *cbCoach;

    QSqlRelationalTableModel *modelFee, *modelSert, *modelSC;
    QTableView *viewFee, *viewSert, *viewSC;

    void CreateWidgets();
    void InitWidgets();

//    QVBoxLayout *CreateInnerTbls();
//    inline QTableView *_InitViewModel(QTableView *aView, QSqlRelationalTableModel *aModel, TblType aType);
//    inline QGroupBox *_AddTable(TblType aType, QTableView *aView, QSqlRelationalTableModel *aModel);
//    inline QGroupBox *_AddTable(TblType aType, QTableView *aView, QSqlRelationalTableModel *aModel, const QString &aTitle);

    bool IsValid() const;
    bool Submit();

public:
    CardSport(QWidget *aParent, TableModel *aModel, int aId);
};

/******************************* Coaches *******************************/

class CardCoach: public Card
{
    Q_OBJECT

private:
    QVector<int> vecClubId;

    QLineEdit *edtName;
    QLineEdit *edtPhone;
    QComboBox *cbClub;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

public:
    CardCoach(QWidget *aParent, TableModel *aTblModel, int aId);
};

/******************************* Clubs *******************************/

class CardClub: public Card
{
    Q_OBJECT

private:
    QLineEdit *edtName;
    QLineEdit *edtAddr;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

public:
    CardClub(QWidget *aParent, TableModel *aTblModel, int aId);
};

/******************************* Sertifications *******************************/

class CardSert: public Card
{
    Q_OBJECT

private:
    QVector<int> vecSportId;
    QVector<int> vecRankFromId;
    QVector<int> vecRankToId;

    QComboBox *cbSport;
    QDateEdit *edtDate;
    QComboBox *cbRankFrom;
    QComboBox *cbRankTo;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

public:
    CardSert(QWidget *aParent, TableModel *aTblModel, int aId);
};

/******************************* Fees *******************************/

class CardFee: public Card
{
    Q_OBJECT

private:
    QVector<int> vecSportId;

    QComboBox *cbSport;
    QDateEdit *edtDate;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

public:
    CardFee(QWidget *aParent, TableModel *aTblModel, int aId);
};


/******************************* Sportsmen-Competiotions *******************************/

class CardSportComp: public Card
{
    Q_OBJECT

private:
    QVector<int> vecSportId, vecCompId, vecCategId;

    QComboBox *cbSport;
    QComboBox *cbComp;
    QComboBox *cbCateg;
    QLineEdit *edtDrawNum;
    QLineEdit *edtUnit;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

public:
    CardSportComp(QWidget *aParent, TableModel *aTblModel, int aId);
};

/******************************* Competiotions *******************************/

class CardComp: public Card
{
    Q_OBJECT

private:
    QLineEdit *edtName;
    QLineEdit *edtNameProt;
    QDateEdit *edtDate;
    QLineEdit *edtLoc;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

private slots:
    void UpdateNameProt();

public:
    CardComp(QWidget *aParent, TableModel *aModel, int aId);
};

/******************************* Categories *******************************/

class CardCateg: public Card
{
    Q_OBJECT

private:
    QLineEdit *edtName;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

public:
    CardCateg(QWidget *aParent, TableModel *aModel, int aId);
};

/******************************* Ranks *******************************/

class CardRank: public Card
{
    Q_OBJECT

private:
    QLineEdit *edtName;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

public:
    CardRank(QWidget *aParent, TableModel *aModel, int aId);
};

/******************************* Prize winners *******************************/

class CardPrzWin: public Card
{
    Q_OBJECT

private:
    QVector<int> vecSportId, vecCompId;

    QComboBox *cbSport;
    QComboBox *cbComp;
    QLineEdit *edtFightsCount;
    QLineEdit *edtFightsWon;
    QLineEdit *edtPlace;
    QLineEdit *edtRegion;
    QLineEdit *edtCity;

    void CreateWidgets();
    void InitWidgets();

    bool IsValid() const;
    bool Submit();

private slots:
    void UpdateCBSport(int aIndex);

public:
    CardPrzWin(QWidget *aParent, TableModel *aModel, int aId);
};

#endif // CARD_H
