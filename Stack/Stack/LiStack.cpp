#include "LiStack.h"

bool InitLiStack(Int_LiStack& L) {
	L = NULL;
	return true;
}
bool InitLiStack_Head(Int_LiStack& L){
	if (NULL == (L = (Int_StackNode*)malloc(sizeof(Int_StackNode))))
		return false;
	L->next = NULL;
	return true;
}

bool EmptyLiStack(Int_LiStack L) {
	if (NULL == L)
		return true;
	else
		return false;
}
bool EmptyLiStack_Head(Int_LiStack L) {
	if (NULL == L->next)
		return true;
	else
		return false;
}

bool PushLiStack(Int_LiStack& L, int Data) {
	Int_StackNode* Node_new;
	if (NULL == (Node_new = (Int_StackNode*)malloc(sizeof(Int_StackNode))))
		return false;

	Node_new->data = Data;
	Node_new->next = L;
	L = Node_new;
	return true;
}
bool PushLiStack_Head(Int_LiStack& L, int Data) {
	Int_StackNode* Node_new;
	if (NULL == (Node_new = (Int_StackNode*)malloc(sizeof(Int_StackNode))))
		return false;

	Node_new->data = Data;
	Node_new->next = L->next;
	L->next = Node_new;
	return true;
}

bool PopLiStack(Int_LiStack& L, int& Data) {
	if (EmptyLiStack(L))
		return false;
	Int_StackNode* Top_Node = L;
	L = Top_Node->next;
	Data = Top_Node->data;
	free(Top_Node);
	return true;
}
bool PopLiStack_Head(Int_LiStack& L, int& Data) {
	if (EmptyLiStack_Head(L))
		return false;
	Int_StackNode* Top_Node = L->next;
	L = Top_Node->next;
	Data = Top_Node->data;
	free(Top_Node);
	return true;
}

bool GetTopLiStack(Int_LiStack L, int& Data) {
	if (EmptyLiStack(L))
		return false;
	Data = L->data;
	return true;
}
bool GetTopLiStack_Head(Int_LiStack L, int& Data) {
	if (EmptyLiStack(L))
		return false;
	Data = L->next->data;
	return true;
}
