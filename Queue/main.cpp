#include <iostream>

using namespace std;

#include "queue.h"

void printElem(ElemType &e);

int main()
{
	Queue Q;
	int select, elem;
	cout << (InitQueue(Q) ? "注册成功" : "注册失败") << endl;
	cout << "输入初始化队列的元素个数" << endl;
	cin >> select;
	for (int i = 0; i < select; i++){
		//cin >> elem;
		if (!EnQueue(Q, i + 1))
			cout << "插入失败" << endl;
	}

	while (1){
		cout << endl;
		cout << "1.PrintElem" << endl;
		cout << "2.EnQueue" << endl;
		cout << "3.DeQueue" << endl;
		cout << "4.GetHead" << endl;
		cout << "5.QueueLength" << endl;
		cout << "6.QueueEmpty" << endl;
		cout << "7.ClearQueue" << endl;
		cout << "8.DestroyQueue" << endl;
		cin >> select;

		system("cls");
		cout << "队列内元素:" << endl;
		QueueTraverse(Q, printElem);
		cout << endl;

		switch (select)
		{
		case 1:
			QueueTraverse(Q, printElem);
			break;
		case 2:
			cout << "输入要添加的元素" << endl;
			cin >> elem;
			cout << "插入" << (EnQueue(Q, elem) ? "成功" : "失败") << endl;
			cout << "添加后队列内的元素" << endl;
			QueueTraverse(Q, printElem); 
			break;
		case 3:
			if (DeQueue(Q, elem))
				cout << "被删除的元素是" << elem << endl;
			else
				cout << "队列内无元素" << endl;
			break;
		case 4:
			if (GetHead(Q, elem))
				cout << "队列顶的元素是" << elem << endl;
			else
				cout << "队列内无元素" << endl;
			break;
		case 5:
			cout << "队列的长度为" << QueueLength(Q) << endl;
			break;
		case 6:
			cout << "队列" << (QueueEmpty(Q) ? "是空队列" : "不是空队列") << endl;
			break;
		case 7:
			cout << "清空" << (ClearQueue(Q) ? "成功" : "失败") << endl;
			break;
		case 8:
			cout << "Destroy" << (DestroyQueue(Q) ? "成功" : "失败") << endl;
			break;
		default:
			DestroyQueue(Q);
			exit(1);
			break;
		}
	}

}

void printElem(ElemType &e)
{
	cout << e << " ";
}