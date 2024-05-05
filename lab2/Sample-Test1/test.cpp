#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Project2/Source.cpp"

struct mas {
	int* ptr;
	int size = 0;
};
typedef struct mas mas;
void recursive(Node* root, mas* A) {
	if (root == NULL) {
		return;
	}
	recursive(root->left, A);
	A->ptr[A->size] = root->data;
	A->size++;
	recursive(root->right, A);
}
int test(int n, Node* head) {
	mas A;
	A.ptr = (int*)malloc(sizeof(int) * n);
	A.size = 0;
	recursive(head, &A);
	for (int i = 0; i < n; ++i) {
		if (A.ptr[i] != i) {
			return 0;
		}
	}
	return 1;
}

TEST(InsertTest, Nulltest) {
	Node* root = NULL;
	int key = 3;
	root = Add(root, 3);
	EXPECT_EQ(root->data, key);
	EXPECT_EQ((void*)root->left, (void*)NULL);
	EXPECT_EQ((void*)root->right, (void*)NULL);
	EXPECT_TRUE(true);
}

TEST(InsertTest, sort_test) {
	Node* root = NULL;


	for (int i = 0; i < 50; ++i) {
		root = Add(root, i);
	}
	int flag = 1;
	mas A;
	A.ptr = (int*)malloc(sizeof(int) * 50);
	A.size = 0;
	recursive(root, &A);
	for (int i = 0; i < 50; ++i) {
		if (A.ptr[i] != i) {
			flag = 0;
		}
	}
	EXPECT_EQ(flag, 1);
	EXPECT_TRUE(true);
}

TEST(InsertTest, unsort_test) {
	Node* root = NULL;


	for (int i = 49; i >= 0; --i) {
		root = Add(root, i);
	}
	for (int i = 99; i >= 50; --i) {
		root = Add(root, i);
	}
	int flag = 1;
	mas A;
	A.ptr = (int*)malloc(sizeof(int) * 100);
	A.size = 0;
	recursive(root, &A);
	for (int i = 0; i < 100; ++i) {
		if (A.ptr[i] != i) {
			flag = 0;
		}
	}
	EXPECT_EQ(flag, 1);
	EXPECT_TRUE(true);
}

TEST(DeleteTest, del_test1) {
	Node* root = NULL;
	root = Add(root, 5);
	root = Add(root, 3);
	root = Add(root, 8);
	root = Delete(root, 5);
	EXPECT_EQ(root->data, 8);
	EXPECT_TRUE(true);
}

TEST(DeleteTest, del_test2) {
	Node* root = NULL;
	root = Add(root, 5);
	root = Add(root, 3);
	root = Add(root, 8);
	root = Add(root, 4);
	root = Delete(root, 4);
	EXPECT_EQ(root->data, 5);
	EXPECT_TRUE(true);
}