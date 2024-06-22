#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* Left, * Right;
}Node;

Node* Insert(Node* node, int data)
{
    // ��尡 ������� ��쿡 �� ��带 ���� �����͸� �ְ� ��ȯ
    if (node == NULL)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->Left = NULL;
        newNode->Right = NULL;

        return newNode;
    }
    else
    {
        // �̹� ��尡 �ִ� ��쿡�� ���ο� �����͸� ��忡 �°� ����
        /*
        TODO: Fill the conditions in Insert function
        */
        // ������ �����Ͱ� ���� ����� �����ͺ��� ������ ���� �ڽ� ���� �̵�
        if (data < node->data)
        {
            node->Left = Insert(node->Left, data);
            return node;
        }
        /*
        TODO: Fill the conditions in Insert function
        */
        // ������ �����Ͱ� ���� ����� �����ͺ��� ũ�� ������ �ڽ� ���� �̵�
        else if (data > node->data)
        {
            node->Right = Insert(node->Right, data);
            return node;
        }
        // �����Ϸ��� �����Ͱ� �̹� Ʈ���� �ִ� ��쿡�� �״�� ��ȯ
        else
        {
            return node;
        }

    }
}


int Search(Node* node, int data)
{
    // ��尡 ��������� �ش� �����Ͱ� Ʈ���� ���ٴ� �޽����� ����ϰ� NULL�� ��ȯ
    if (node == NULL) {
        printf("No Node %d ", data);
        return NULL;
    }

    // �����͸� ã���� �ش� �����͸� ��ȯ
    if (node->data == data)
    {
        return node->data;
    }
    // ã������ �����Ϳ� ���� ����� �����͸� ���Ͽ� ������ �������� �̵�
    else
    {
        /*
        TODO: Implement the Search function conditions
        */
        if (data < node->data)
        {
            return Search(node->Left, data);
        }
        else if (data > node->data)
        {
            return Search(node->Right, data);
        }
    }
}

Node* Delete(Node* node, int data)
{
    if (node == NULL) return NULL;

    if (node->data == data)
    {
        Node* deleteNode = node;
        /*
        TODO: Implement the Delete function conditions*/

        if (node->Left == NULL && node->Right == NULL) {
            free(deleteNode);
            return NULL;
        }
        else if (node->Left == NULL) {
            Node* temp = node->Right;
            free(deleteNode);
            return temp;
        }
        else if (node->Right == NULL) {
            Node* temp = node->Left;
            free(deleteNode);
            return temp;
        }
        else {
            Node* temp = node->Right;
            while (temp->Left != NULL) {
                temp = temp->Left;
            }
            node->data = temp->data;
            node->Right = Delete(node->Right, temp->data);
        }

        return node;
    }
    else {
        if (data < node->data) {
            node->Left = Delete(node->Left, data);
        }
        else if (data > node->data) {
            node->Right = Delete(node->Right, data);
        }
    }

    return node;
}




// BST Print function 

/* Do not Modify on Submition */


int getHeight(Node* node) {
    if (node == NULL) return 0;
    int leftHeight = getHeight(node->Left);
    int rightHeight = getHeight(node->Right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(Node* node, int level, int currentLevel, int indentSpace) {
    if (node == NULL) {
        if (currentLevel == level) {
            for (int i = 0; i < indentSpace; i++) printf(" ");
        }
        return;
    }
    if (level == currentLevel) {
        printf("%*s%d", indentSpace, "", node->data);
    }
    else {
        printLevel(node->Left, level, currentLevel + 1, indentSpace);
        printLevel(node->Right, level, currentLevel + 1, indentSpace);
    }
}

void ShowInOrder(Node* root) {
    int height = getHeight(root);
    int indentSpace = 2;
    for (int i = 0; i < height; i++) {
        printLevel(root, i, 0, indentSpace * (height - i));
        printf("\n");
    }
    printf("\n");
}

// Main Function

/* Do not Modify on Submition */

int main()
{
    Node* root = NULL;

    //INSERT
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 32);
    root = Insert(root, 4);
    root = Insert(root, 13);
    root = Insert(root, 25);
    root = Insert(root, 55);

    //SHOW
    ShowInOrder(root);
    /*
       20
    10    32
  4  13  25  55
    */

    //SEARCH
    printf("Node: %d\n", Search(root, 12));
    /*
    No Node 12 Node: 0
    */
    //SEARCH
    printf("Node %d\n", Search(root, 13));
    /*
    Node: 13
    */

    //DELETE
    root = Delete(root, 32);

    ShowInOrder(root);
    /*
       20
    10    55
  4  13  25
    */
}
