#include <iostream>

using namespace std;

#include "queue.h"

void printElem(ElemType &e);

int main()
{
	Queue Q;
	int select, elem;
	cout << (InitQueue(Q) ? "ע��ɹ�" : "ע��ʧ��") << endl;
	cout << "�����ʼ�����е�Ԫ�ظ���" << endl;
	cin >> select;
	for (int i = 0; i < select; i++){
		//cin >> elem;
		if (!EnQueue(Q, i + 1))
			cout << "����ʧ��" << endl;
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
		cout << "������Ԫ��:" << endl;
		QueueTraverse(Q, printElem);
		cout << endl;

		switch (select)
		{
		case 1:
			QueueTraverse(Q, printElem);
			break;
		case 2:
			cout << "����Ҫ��ӵ�Ԫ��" << endl;
			cin >> elem;
			cout << "����" << (EnQueue(Q, elem) ? "�ɹ�" : "ʧ��") << endl;
			cout << "��Ӻ�����ڵ�Ԫ��" << endl;
			QueueTraverse(Q, printElem); 
			break;
		case 3:
			if (DeQueue(Q, elem))
				cout << "��ɾ����Ԫ����" << elem << endl;
			else
				cout << "��������Ԫ��" << endl;
			break;
		case 4:
			if (GetHead(Q, elem))
				cout << "���ж���Ԫ����" << elem << endl;
			else
				cout << "��������Ԫ��" << endl;
			break;
		case 5:
			cout << "���еĳ���Ϊ" << QueueLength(Q) << endl;
			break;
		case 6:
			cout << "����" << (QueueEmpty(Q) ? "�ǿն���" : "���ǿն���") << endl;
			break;
		case 7:
			cout << "���" << (ClearQueue(Q) ? "�ɹ�" : "ʧ��") << endl;
			break;
		case 8:
			cout << "Destroy" << (DestroyQueue(Q) ? "�ɹ�" : "ʧ��") << endl;
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