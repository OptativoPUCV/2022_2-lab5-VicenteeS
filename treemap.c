#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) 
{
  TreeMap * newMap = (TreeMap *)malloc(sizeof(TreeMap));

  newMap->root = NULL;
  newMap->current = NULL;
  newMap->lower_than = lower_than;
  
  return (newMap);
}


void insertTreeMap(TreeMap * tree, void* key, void * value){
  if(searchTreeMap(tree, key) == NULL)
  {
    if(tree->root == NULL)
    {
      TreeNode *nodo = createTreeNode(key, value);
      
      tree->root = nodo;
      tree->current = nodo;
      
    }
    else
    {
      TreeNode *nActual = tree->root;
      while(nActual != NULL)
      {          
        if(tree->lower_than(nActual->pair->key, key) == 0)
        {
          nActual = nActual->left;
        }
        else
        {
          nActual = nActual->right;
        }
      }
      TreeNode *nodo = createTreeNode(key, value);
      //nodo->parent = nActual->parent;
      if(tree->lower_than(nActual->pair->key, key) == 0)
      {
        nActual->right = nodo;
      }
      else
      {
        nActual->left = nodo;
      }
      
      tree->current = nActual;
      
    }
  }
}

TreeNode * minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) 
{
  TreeNode *nodoActual = tree->root;
  
  if(tree->root == NULL)
  {
    return(NULL);
  }
  else
  {
    while(nodoActual != NULL)
    {
      if(is_equal(tree, nodoActual->pair->key, key) == 1)
      {
        tree->current = nodoActual;
        return (nodoActual->pair);
      }
      if(tree->lower_than(nodoActual->pair->key, key) == 0)
      {
        nodoActual = nodoActual->left;
      }
      else
      {
        nodoActual = nodoActual->right;
      }
    }
  }
  return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
