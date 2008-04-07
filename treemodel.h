#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "borderstruct.h"

class TreeItem;
class Renderer;
class MObject;
class MAbstractView;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
	TreeModel(QObject *parent = 0);
	~TreeModel();

	QVariant data(const QModelIndex &index, int role) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	Qt::ItemFlags flags(const QModelIndex &index) const;
	QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
	QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
	QModelIndex index(const TreeItem *item, int column) const;

	QModelIndex parent(const QModelIndex &index) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	TreeItem *itemFromIndex(const QModelIndex &index) const;

	bool appendTopLevelItem(TreeItem *item);
	void add(MObject *object);
	void draw(Renderer *renderer);
	void calculateBorders(BorderStruct &borders);

public:
	void setCurrentView(MAbstractView *currentView);

private:
	TreeItem *rootItem;
	MAbstractView *m_currentView;
};

#endif
