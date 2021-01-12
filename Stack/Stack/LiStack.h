#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Listack {
	int data;
	struct Listack* next;
}Int_StackNode, *Int_LiStack;

bool InitLiStack(Int_LiStack& L);
bool InitLiStack_Head(Int_LiStack& L);

bool EmptyLiStack(Int_LiStack L);
bool EmptyLiStack_Head(Int_LiStack L);

bool PushLiStack(Int_LiStack& L, int Data);
bool PushLiStack_Head(Int_LiStack& L, int Data);

bool PopLiStack(Int_LiStack& L, int& Data);
bool PopLiStack_Head(Int_LiStack& L, int& Data);

bool GetTopLiStack(Int_LiStack L, int& Data);
bool GetTopLiStack_Head(Int_LiStack L, int& Data);
