#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Node{
	public:
		int veri;
		Node* sonraki;
};

class Liste{
	private:
		Node* bas;
	public:
		Liste(){bas=NULL;};
		bool bosmu(){return bas==NULL;};
		Node* basa_ekle(int x);
		Node* sona_ekle(int x);
		Node* araya_ekle(int x,int index);
		void yazdir();
};

Node* Liste::basa_ekle(int x)
{
	Node* yeniNode = new Node;
	yeniNode->veri=x;
	yeniNode->sonraki=NULL;
	
	if(bosmu())
	{
		bas=yeniNode;
	}
	else
	{
		yeniNode->sonraki=bas;
		bas=yeniNode;
	}
	//return bas;
}

Node* Liste::sona_ekle(int x)
{
	Node* yeniNode = new Node;
	yeniNode->veri=x;
	yeniNode->sonraki=NULL;
	Node* kontrolNode = new Node;
	kontrolNode=bas;
	
	if(bosmu())
	basa_ekle(x);
	else
	{
		while(kontrolNode->sonraki!=NULL)
		{
			kontrolNode=kontrolNode->sonraki;
		}
		kontrolNode->sonraki=yeniNode;
	}
}
// sona ekleme
Node* Liste::araya_ekle(int x,int index)
{
	Node* yeniNode = new Node;
	yeniNode->veri=x;
	yeniNode->sonraki=NULL;
	Node* kontrolNode = new Node;
	kontrolNode=bas;
	int sayac=0;
	if(bosmu())
	cout<<"liste bos!";
	else
	{
		while(kontrolNode->sonraki!=NULL&&sayac<index-1)
		{
			kontrolNode=kontrolNode->sonraki;
			sayac++;
		}
	    yeniNode->sonraki=kontrolNode->sonraki;
	    kontrolNode->sonraki=yeniNode;
		
	}
}

void Liste::yazdir()
{
	Node* kontrolNode = new Node;
	kontrolNode=bas;
	if(bosmu())
	 {
	 	cout<<"liste bos!"<<endl;
	 }
	else
	{
	
		while(kontrolNode)
		{
			cout<<kontrolNode->veri<<endl;
			kontrolNode=kontrolNode->sonraki;
		}
			
	}
	cout<<"liste sonu"<<endl;	
}

int main(int argc, char** argv) 
{
	int a,b;
	scanf("%d %d",&a,&b);
	Liste l;
	cout<<"dizi su hali alir"<<endl;
	l.basa_ekle(5);
	l.basa_ekle(5);
	l.basa_ekle(5);
	l.basa_ekle(10);
	l.basa_ekle(10);
	l.basa_ekle(1);
	l.basa_ekle(19);
	l.basa_ekle(13);
	l.araya_ekle(b,a);
	l.yazdir();
	
	return 0;
}
