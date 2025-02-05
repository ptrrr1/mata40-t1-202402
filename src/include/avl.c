#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

void rot_right(avl_tree** pt, int* h) {
	avl_tree* ptu = (*pt)->left;
	if (ptu->bal == -1) {
		// Rotação Simples
		(*pt)->left = ptu->right;
		ptu->right = (*pt);
		// Balanceamento
		(*pt)->bal = 0;
		//
		(*pt) = ptu;
	} else {
		// Rotação Esquerda
		avl_tree* ptv = ptu->right;
		ptu->right = ptv->left;
		ptv->left = ptu;
		// Rotação Direita
		(*pt)->left = ptv->right;
		ptv->right = (*pt);
		//Balanceamento
		if (ptv->bal == -1) { (*pt)->bal = 1; } else { (*pt)->bal = 0; }
		if (ptv->bal == 1) { ptu->bal = -1; } else { ptu->bal = 0; }
		//
		(*pt) = ptv;
	}
	(*pt)->bal = 0;
	*h = 0;
}

void rot_left(avl_tree** pt, int* h) {
	avl_tree* ptu = (*pt)->right;
	if (ptu->bal == 1) { // Rotação Simples
		(*pt)->right = ptu->left;
		ptu->left = (*pt);
		//Balanceamento
		(*pt)->bal = 0;
		//
		(*pt) = ptu;
	} else {
		// Rotação Esquerda
		avl_tree* ptv = ptu->left;
		ptu->left = ptv->right;
		ptv->right = ptu;
		// Rotação Direita
		(*pt)->right = ptv->left;
		ptv->left = (*pt);
		//Balanceamento
		if (ptv->bal == 1) { (*pt)->bal = -1; } else { (*pt)->bal = 0; }
		if (ptv->bal == -1) { ptu->bal = 1; } else { ptu->bal = 0; }
		//
		(*pt) = ptv;
	}
	(*pt)->bal = 0;
	*h = 0;
}

void insert_elem(avl_tree** root, int* h, int x) {
	if (*root == NULL) {
		*root = (avl_tree*)malloc(sizeof(avl_tree));
		(*root)->key = x;
		(*root)->bal = 0;
		(*root)->left = NULL;
		(*root)->right = NULL;
		*h = 1;
	} else {
		if (x < (*root)->key) {
			insert_elem(&((*root)->left), h, x);
			//
			if (*h) {
				if ((*root)->bal == 1) { (*root)->bal = 0; *h = 0; }
				else if ((*root)->bal == 0) { (*root)-> bal = -1; }
				else if ((*root)->bal == -1) { rot_right(root, h); }
			}
		} else {
			insert_elem(&((*root)->right), h, x);
			//
			if (*h) {
				if ((*root)->bal == -1) { (*root)->bal = 0; *h = 0; }
				else if ((*root)->bal == 0) { (*root)-> bal = 1; }
				else if ((*root)->bal == 1) { rot_left(root, h); }
			}
		}
	}
}