#ifndef TABLE_H
#define TABLE_H

#include "setting.h"
#include "card.h"

/******************************* Table (basic) *******************************/

typedef QMap<int, Card *> MapCard;

class Table: public QMainWindow
{
    Q_OBJECT

private:
    TblType type;
    MapCard mapCard;

    Qt::SortOrder prevSortVal;
    int prevSortCol;

    void CreateWidgets();

    void SetTableHeaders();

private slots:
    void SetFirst();
    void SetNext();
    void SetPrev();
    void SetLast();
    void Add();
    void Delete();
    void Edit();

    void OpenCard(QModelIndex aMIndex);
    void CloseCard(QObject *aObj);
    void SetSort(int aI);

    void ApplyTableSettings();
    void SaveTableSettings();

protected:
    TableView *view;

    TableModel *model;

//    void Init(const QString &aTitle, const QString &aTblName);
    virtual Card *CreateCard(int aId) const = 0;

    void Init(const QString &aQuery);

public:
    Table(QWidget *aParent, TblType aType);
    ~Table();
    TblType Type() const;
};

/******************************* Sportsmen *******************************/

class TblSport: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblSport(QWidget *aParent = 0);
};

/******************************* Coaches *******************************/

class TblCoach: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblCoach(QWidget *aParent = 0);
};

/******************************* Clubs *******************************/

class TblClub: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblClub(QWidget *aParent = 0);
};

/******************************* Certifications *******************************/

class TblSert: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblSert(QWidget *aParent = 0);
};

/******************************* Fee *******************************/

class TblFee: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblFee(QWidget *aParent = 0);
};


/******************************* Sportsmen-Competiotions *******************************/

class TblSportComp: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblSportComp(QWidget *aParent = 0);
};

/******************************* Competiotions *******************************/

class TblComp: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblComp(QWidget *aParent = 0);
};

/******************************* Categories *******************************/

class TblCateg: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblCateg(QWidget *aParent = 0);
};

/******************************* Ranks *******************************/

class TblRank: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblRank(QWidget *aParent = 0);
};

/******************************* Prize winners *******************************/

class TblPrzWin: public Table
{
    Q_OBJECT

private:
    Card *CreateCard(int aId) const;

public:
    TblPrzWin(QWidget *aParent = 0);
};

#endif // TABLE_H

