#include <iostream>
#include <cmath>
using namespace std;

int list = 0;//счетчик для листьев
int tabs = 0; //Для создания отступов в использовании print функции

//Структура для ветки
struct Branch
{
	//Поле данных
	int data; 

	 //Указатели на ветки (левый и правый)
	Branch* LeftBranch;

	Branch* RightBranch;

};

//Функция внесения данных

void Add(int adata, Branch*& aBranch)
{
	if (!aBranch) //Проверка на сущ ветки

	//Создание ветки и заполнение информацией
	{
		aBranch = new Branch;

		aBranch->data = adata;
		aBranch->LeftBranch = 0;

		aBranch->RightBranch = 0;
		return;
	}

	else //Иначе сравниваем вводимую информацию

		//если оно меньше того, что в этой ветке - добавим влево
		if (aBranch->data > adata) Add(adata, aBranch->LeftBranch);

			//иначе в ветку справа
			else Add(adata, aBranch->RightBranch); //иначе в ветку справа
}

//Функция рисовки вертикально бин.дерева
void print(Branch* aBranch)
{
	if (!aBranch) return; //Если ветки не существует - выходим. Выводить нечего

	tabs += 7; //Иначе увеличим счётчик для отступов

	print(aBranch->LeftBranch); //Вывод ветки и ее подветки слева

	for (int i = 0; i < tabs; i++) cout << " "; //отступы после вывода ветки

	cout << aBranch->data << endl;//Данные данной ветки
	print(aBranch->RightBranch);//Ветка справа

	tabs -= 7; //Возврат отступов

	cout << endl;
	return;
}

void bypass_tree(Branch*& aBranch)
{
	if (aBranch == NULL) return; //Если дерева нет, выходим
	bypass_tree(aBranch->LeftBranch); //Обошли левое поддерево
	cout << aBranch->data << endl; //Посетили узел
	bypass_tree(aBranch->RightBranch); //Обошли правое поддерево
}


int leaf_num(Branch*& aBranch)
{
	if (aBranch == NULL)	return 0;	//Если дерева нет, выходим

	if (aBranch->LeftBranch == NULL && aBranch->RightBranch == NULL)	list++;

	leaf_num(aBranch->LeftBranch); //Обошли левое поддерево
	leaf_num(aBranch->RightBranch); //Обошли правое поддерево
	return list;
}


void add_elem(int adata, Branch*& aBranch)
{

	if (!aBranch)
	{
		aBranch = new Branch;
		aBranch->data = adata;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else 
		if (adata < aBranch->data)		add_elem(adata, aBranch->LeftBranch);
			else 
				if (adata > aBranch->data)		add_elem(adata, aBranch->RightBranch);
}

void is_Empty(Branch*& aBranch)
{
	cout << "Checking the tree....." << endl;

	if (!aBranch) cout << "BIN-tree empty...";

	else cout << "BIN-tree NO empty...";
	
	cout << endl;
}

void DeleteTree(Branch* aBranch)
{
	if (!aBranch) return;

	DeleteTree(aBranch->LeftBranch);
	DeleteTree(aBranch->RightBranch);

	delete aBranch;
	return;
}

Branch* del_elem(Branch*& aBranch, int aData) 
{
	if (aBranch == NULL)	return aBranch;

	if (aData == aBranch->data) 
	{
		Branch* tmp;
		if (aBranch->RightBranch == NULL)	tmp = aBranch->LeftBranch;

		else 
		{
			Branch* ptr = aBranch->RightBranch;

			if (ptr->LeftBranch == NULL) 
			{
				ptr->LeftBranch = aBranch->LeftBranch;
				tmp = ptr;
			}

			else
			{
				Branch* pmin = ptr->LeftBranch;

				while (pmin->LeftBranch != NULL)
				{
					ptr = pmin;
					pmin = ptr->LeftBranch;
				}
				ptr->LeftBranch = pmin->RightBranch;
				pmin->LeftBranch = aBranch->LeftBranch;
				pmin->RightBranch = aBranch->RightBranch;
				tmp = pmin;
			}
		}

		delete aBranch;
		return tmp;
	}

	else 
		if (aData < aBranch->data)	aBranch->LeftBranch = del_elem(aBranch->LeftBranch, aData);
			else aBranch->RightBranch = del_elem(aBranch->RightBranch, aData);

	return aBranch; //Возврат после изменений
}

int main()

{
	Branch* tree = 0;
	int col_branch;
	int elem;
	cout << "Enter the number of branch elements: ";
	cin >> col_branch;
	cout << endl;

	is_Empty(tree);

	for (int i = 0; i < col_branch; i++)	Add(rand() % 96, tree);

	is_Empty(tree);

	cout << "Print BIN-tree: " << endl;
	print(tree);

	cout << "Direct bypass BIN-tree:" << endl;
	bypass_tree(tree);
	cout << endl;

	cout << "Entering a new element into the BIN-tree: " << endl;
	cout << "Add new element to the BIN-tree: "; cin >> elem;
	add_elem(elem,tree);

	cout << "Print BIN-tree: " << endl;
	print(tree);

	cout << "Enter the delete-element: "; cin >> elem;
	del_elem(tree, elem);

	cout << "Print BIN-tree: " << endl;
	print(tree);


	cout << "Leaf Calculator -> Number of leaves: " << leaf_num(tree) << endl;

	DeleteTree(tree);
	cout << "Delete tree....." << endl;
}