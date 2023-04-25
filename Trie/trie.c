#include "trie.h"

/* */
Trie *create_node (char data) {
  Trie *node = (Trie *)malloc(sizeof(Trie));
  node->data = data;
  node->end = FALSE;
  node->nchild = 0;
  int i;
  //size is the alphabet size 
  for (i = 0; i < size; i++) {
    node->keys[i] = NULL;	   
  }
  return node;   
}

/* */
void free_node (Trie *node) {
  int i;
  for (i = 0; i < size; i++) {
    if (node->keys[i] != NULL) {
      free_node (node->keys[i]);	    
    }
  }	  
  free (node);
}

int letterExists(Trie* root, char letter)
{
  return (root->keys[letter - 'a'] != NULL);
}

/* */
Trie *insert (Trie *root, char *word) {
  if (search_auxiliary(root, word))
  {
    printf("Word already inserted!");
    return root;
  }
  if (!word)
    return root;
  if (word[0] == '\0')
    return NULL;

  if (letterExists(root, word[0]))
  {
    // se eu acabei de ler a palavra e todas as letras já existiam
    if (insert(root->keys[word[0] - 'a'], &word[1]) == NULL) 
      root->keys[word[0] - 'a']->end = TRUE;
    //else 
    root->nchild++;
    return root;
  }

  Trie* newRoot = root;
  
  for (int i = 0; word[i] != '\0'; i++)
  {
    newRoot->keys[word[i] - 'a'] = create_node(word[i]);
    newRoot->nchild++;
    newRoot = newRoot->keys[word[i] - 'a'];
  }
  
  newRoot->end = TRUE;
  
  return root;  	
}

/* */
int search_auxiliary (Trie *root, char *word) {
  if (!word)
  {
    printf("Error: word not provided");
    return FALSE;
  }

  for (int i = 0; word[i] != '\0'; i++)
  {
    //printf("%c", word[i]);
    if (!letterExists(root, word[i]))
      return FALSE;
    root = root->keys[word[i] - 'a'];
  }
  // printf("Root->end %d", root->end);
  // printf("root->data %c", root->data);
  // printf("\n");
  if (root->end == TRUE)
    return TRUE;
  return FALSE;
}

void search (Trie *root, char *word) {
  if (search_auxiliary (root, word))
    printf("Word %s found!\n", word);
  else  
    printf("Error: word %s not found!\n", word);
}

/* */
void print (Trie *root, int level) {
  if (root != NULL) {
    int i;
    if (root->data == '\0')
      printf ("(null)");	    
    for (i = 0; i < level; i++) {
      printf ("| ");
    }	    
    printf ("%c (%d - %d)\n", root->data, root->end, root->nchild);
    for (i = 0; i < size; i++) {
      print (root->keys[i], level+1);      
    }
  }	  
}

void delete (Trie *root, char *word) {
  if (!search_auxiliary(root, word))
  {
    printf("Can't remove because word isn't in this tree!");
    return;
  }
  
  for (int i = 0; word[i] != '\0'; i++)
  {
    root->nchild--;
    if (root->keys[word[i] - 'a']->nchild <= 1)
    {
      free_node(root->keys[word[i] - 'a']);
      // free node já cuida de eliminar todos os filhos
      root->keys[word[i] - 'a'] = NULL;
      return;
    }
    root = root->keys[word[i] - 'a'];
  }
  root->end = FALSE;
}  
 
