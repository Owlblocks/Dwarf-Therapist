/*
Dwarf Therapist
Copyright (c) 2009 Trey Stout (chmod)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef STATETABLEVIEW_H
#define STATETABLEVIEW_H

#include <QtGui>

class UberDelegate;
class RotatedHeader;
class Dwarf;

class StateTableView : public QTreeView
{
	Q_OBJECT

public:
	StateTableView(QWidget *parent = 0);
	~StateTableView();

	void setModel(QAbstractItemModel *model);
	UberDelegate *get_delegate() {return m_delegate;}

	public slots:
		void filter_dwarves(QString text);
		void set_grid_size(int new_size);
		void set_single_click_labor_changes(bool enabled);
		void set_allow_grid_focus(bool enabled);
		void jump_to_dwarf(QTreeWidgetItem* current, QTreeWidgetItem* previous);

protected:
	QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);

private:
	UberDelegate *m_delegate;
	RotatedHeader *m_header;
	bool m_grid_focus;
	bool m_single_click_labor_changes;

	private slots:
		void new_custom_profession();

signals:
	void new_custom_profession(Dwarf *d);

};
#endif // STATETABLEVIEW_H