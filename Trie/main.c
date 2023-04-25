#include "trie.h"

int main () {

  printf("Teste");
  Trie *root = create_node ('\0');

  print(root, 0);

  //root = insert (root, "maria");
  
  print (root, 0);

  search (root, "maria");

  delete (root, "mar");
  //delete(root, "maria");
  print (root, 0);
  insert(root, "mar");
  insert(root, "mel");
  printf("\n\n\n\n\n");
  insert(root, "mola");
  print(root, 0);

  //delete(root, "marco");
  //print(root, 0);

  delete(root, "mar");
  print(root, 0);

  return 0;
}
