/* Includes ----------------------------------------------------- */
#include "stdio.h"
#include "stdlib.h"
#include "DateTime.h"
#include "Objects.h"
#include "Headers.h"
#include "Structs.h"
#include <iostream>
#include <string.h>
#include <time.h>
#pragma warning ( disable : 4996 )

using namespace std;

/* Helper function prototypes ----------------------------------- */
void PrintSingleObject(Object7* object);
stack* AddToStack(stack* pStack, void* object);
stack* PopFromStack(stack* pStack, void** object);
void PrintStack(stack* pStack);
void PrintNode(Node* pNode);

/* Mandatory functions prototypes-------------------------------- */
void PrintObjects(HeaderA* pStruct2);
Object7* RemoveExistingObject(HeaderA** pStruct2, const char* pExistingID);
int InsertNewObject(HeaderA** pStruct2, const char* pNewID, int NewCode);
Node* CreateBinaryTree(HeaderA* pStruct2);
void TreeTraversal(Node* pTree);
Node* DeleteTreeNode(Node* pTree, unsigned long int Code);

/* Global variable defines -------------------------------------- */

/* Main function ------------------------------------------------ */
int main()
{
	// Kirjutage lähtestruktuuri genereeriv lause. See on:
	// b) Struct2 puhul:
	HeaderA* pStruct = GetStruct2(7, 1); // O, N
	// O asemel kirjutage juhendaja poolt antud objekti indeks.
	// N asemel kirjutage juhendaja poolt antud objektide arv3.
	// N ei ole kunagi 0

	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Eaaroot", 10));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Firstright", 11));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Firstleft", 9));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Secondleft", 8));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Qxoyoogl"));
	PrintObjects(pStruct);
	printf("---------------------------------\n");
	Node* pTree = CreateBinaryTree(pStruct);
	//cout << "\nPointer to the start of the tree: " << pTree << ".\nObject at the root: " << flush;
	printf("---------------------------------\n");
	TreeTraversal(pTree);
	printf("---------------------------------\n");
	pTree = DeleteTreeNode(pTree, 10);
	printf("---------------------------------\n");
	TreeTraversal(pTree);



	/*
	pStruct with 5 elements:
		1) Iihxsknx 36666300 07 Nov 2019
		2) Mxfsf 4455511 07 Nov 2019
		3) Pkdrs 64866018 07 Nov 2019
		4) Qxoyoogl 422218 07 Nov 2019
		5) Sqdsb 16533168 07 Nov 2019
	*/
	/*
	HeaderA* additions = GetStruct2(7, 100);

	PrintObjects(pStruct);
	printf("---------------------------------\n");
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Dx", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Db", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Dz", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Dk", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Aa", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Wu", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Wa", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Zw", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Za", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "wK", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "Wa", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "WW", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "W8", 123));
	printf("InsertNewObject outcome: %i\n", InsertNewObject(&pStruct, "W_", 123));
	printf("---------------------------------\n");
	PrintObjects(pStruct);
	printf("---------------------------------\n");
	PrintSingleObject(RemoveExistingObject(&pStruct, "Dx"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Db"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Dz"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Dk"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Aa"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Wu"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Wa"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Zw"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Za"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "wk"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "Wa"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "WW"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "W8"));
	PrintSingleObject(RemoveExistingObject(&pStruct, "D_"));
	printf("---------------------------------\n");
	PrintObjects(pStruct);
	*/
	return 0;
}

/* User functions ----------------------------------------------- */
void PrintSingleObject(Object7* object) {
	//printf("######################\n");
	if (object != 0) {
		char* pID = object->pID;
		unsigned long int Code = object->Code;
		Date2* pDate = object->pDate2;
		printf("%s %lu %02d %s %04d\n", pID, Code, pDate->Day, pDate->Month, pDate->Year);
	}
	else {
		printf("pointer to object was 0\n");
	}
	//printf("######################\n");
};
stack* AddToStack(stack* pStack, void* object) {
	errno = 0;
	stack* pNew = new stack;
	if (!object) {
		errno = EINVAL;
		return pStack;
	}
	pNew->pObject = object;
	pNew->pNext = pStack;
	return pNew;
};
stack* PopFromStack(stack* pStack, void** object) {
	stack* p;
	if (!pStack) {
		*object = 0;
		return pStack;
	}
	*object = (ob7*)pStack->pObject;
	p = pStack->pNext;
	free(pStack);
	return p;
};
void PrintStack(stack* pStack) {
	while (pStack != 0)
	{
		PrintSingleObject((ob7*)pStack->pObject);
		pStack = pStack->pNext;
	}
}
int InsertNewObject(HeaderA** object, const char* pNewID, int NewCode) {
	// Check pNewID formating
	int counter = 0;
	while (*(pNewID + counter) != '\0') {
		if (counter == 0 && !isupper(*(pNewID))) {
			//printf("pID: %s first charater is not Uppercase: %c\n", pNewID, *(pNewID + counter));
			return 0;
		}
		else if (!isalpha(*(pNewID + counter))) {
			//printf("pID: %s contains non alphabetic charater: %c\n", pNewID, *(pNewID + counter));
			return 0;
		}
		else if (counter != 0 && !islower(*(pNewID + counter))) {
			//printf("pID: %s contains uppercase : %c\n", pNewID, *(pNewID + counter));
			return 0;
		}
		counter++;
	}
	// Declare initial variables
	HeaderA* currentStruct = *object;
	HeaderA* nextStruct = currentStruct->pNext;
	Object7* currentObject = NULL;
	Object7* nextObject = NULL;
	int isFirstStruct = 1;

	// Create the new object
	Object7* insertObject = (Object7*)calloc(1, sizeof(Object7));
	insertObject->Code = NewCode;
	insertObject->pID = (char*)pNewID;
	time_t rawTime;
	time(&rawTime);
	insertObject->pDate2 = (Date2*)calloc(1, sizeof(Date2));
	if (insertObject->pDate2) {
		GetDate2(rawTime, insertObject->pDate2);
	}
	else {
		printf("Failed calloc() for Date2");
	}
	//cout << "The new object to be added: " << flush;
	//PrintSingleObject(insertObject);

	// Find where to put the object
	while (currentStruct) {
		//printf("Looking for [%d] at [%d] \t %c|%c|%s\n", *pNewID, currentStruct->cBegin, *pNewID,currentStruct->cBegin,pNewID);
		if (*pNewID == currentStruct->cBegin) {
			//printf("HeaderA already exists\n");
			currentObject = (Object7*)currentStruct->pObject;
			nextObject = currentObject->pNext;
			while (currentObject) {
				//printf("Want to place: %s\tlooking at: %s\t%d\n", insertObject->pID,currentObject->pID, !strcmp(insertObject->pID, currentObject->pID));
				if (!strcmp(insertObject->pID, currentObject->pID)) {
					//printf("Object with that name already exists\n");
					return 0;
				}
				else if (currentObject == currentStruct->pObject && strcmp(currentObject->pID, insertObject->pID) > 0) {
					//printf("Want to place element to be first\n");
					currentStruct->pObject = insertObject;
					insertObject->pNext = currentObject;
					return 1;
				}
				else if (!nextObject || (strcmp(currentObject->pID, insertObject->pID) < 0 && strcmp(insertObject->pID, nextObject->pID) < 0)) {
					//printf("Reached end of list\n");
					currentObject->pNext = insertObject;
					insertObject->pNext = nextObject;
					return 1;
				}
				currentObject = currentObject->pNext;
				if (currentObject)nextObject = currentObject->pNext;
			}
			break;

		}
		else if (isFirstStruct && (!nextStruct || *pNewID < nextStruct->cBegin)) {
			//printf("Need to point the start to a newly created header\n");
			HeaderA* insertHeader = (HeaderA*)calloc(1, sizeof(HeaderA));
			*object = insertHeader;
			insertHeader->cBegin = *pNewID;
			insertHeader->pNext = currentStruct;
			insertHeader->pObject = insertObject;
			return 1;
		}
		else if (!nextStruct || (*pNewID > currentStruct->cBegin&&* pNewID < nextStruct->cBegin)) {
			//printf("HeaderA doesn't exist yet and should be made infront of the next one\n");
			HeaderA* insertHeader = (HeaderA*)calloc(1, sizeof(HeaderA));
			insertHeader->cBegin = *pNewID;
			insertHeader->pNext = nextStruct;
			insertHeader->pObject = insertObject;
			currentStruct->pNext = insertHeader;
			return 1;
		}
		isFirstStruct = 0;
		currentStruct = currentStruct->pNext;
		if (currentStruct)nextStruct = currentStruct->pNext;
	}
	return 0;
}
Object7* RemoveExistingObject(HeaderA** object, const char* pExistingID) {
	HeaderA* currentStruct = *object;
	HeaderA* previousStruct = NULL;
	Object7* currentObject = NULL;
	Object7* previousObject = NULL;
	int isFirstStruct = 1;

	while (currentStruct) {
		//printf("Looking for [%d] at [%d] \t %c|%c|%s\n", *pExistingID, currentStruct->cBegin, *pExistingID,currentStruct->cBegin,pExistingID);
		if (*pExistingID == currentStruct->cBegin) {
			currentObject = (Object7*)currentStruct->pObject;
			previousObject = currentObject;
			while (currentObject) {
				//printf("Looking for: [%s] at [%s]",pExistingID,currentObject->pID);
				if (!strcmp(currentObject->pID, pExistingID)) {
					//printf("\t<-found object with code: %ul\n", currentObject->Code);
					previousObject->pNext = currentObject->pNext;
					if (!currentObject->pNext && currentObject == currentStruct->pObject) {
						if (isFirstStruct) {
							//printf("Object is the only one in header and from the first header\n");
							*object = currentStruct->pNext;
						}
						else {
							previousStruct->pNext = currentStruct->pNext;
						}
					}
					//if (currentObject->pNext == 0)printf("Element is last in it's list -- don't really care\n");
					else if (currentObject == currentStruct->pObject) {
						//printf("Element is first in it's list\n");
						currentStruct->pObject = currentObject->pNext;
					}
					return currentObject;
				}
				else {
					//printf("\t<- not found moving on\n");
				}
				previousObject = currentObject;
				currentObject = currentObject->pNext;
			}
			break;
		}
		else if (*pExistingID < currentStruct->cBegin) break;
		//printf("%c %s %d\n", currentStruct->cBegin, pNewID, NewCode);
		isFirstStruct = 0;
		previousStruct = currentStruct;
		currentStruct = currentStruct->pNext;
	}
	return 0;
}
void PrintObjects(HeaderA* object) {
	//stack* test = 0;


	int counter = 1;
	char index = object->cBegin;
	heada* nextGroup = object;
	while (nextGroup) {
		//printf("------------------------\nPrinting from group: %c\n", index);
		Object7* obj = (Object7*)nextGroup->pObject;
		while (obj) {
			printf("%d) ", counter);
			PrintSingleObject(obj);
			//test = AddToStack(test, obj);
			// Move to the next HeaderA object
			counter++;
			obj = obj->pNext;
		}
		// Move on to the next HeaderA group
		nextGroup = nextGroup->pNext;
		if (nextGroup != 0) index = nextGroup->cBegin;
	}
	//PrintStack(test);
}
Node* CreateBinaryTree(HeaderA* object) {
	// Create the root of the tree
	Node* pRoot = new Node;
	pRoot->pObject = 0;
	pRoot->pLeft = 0;
	pRoot->pRight = 0;

	// Create a placeholder/search node
	Node* pCurrentNode = new Node;


	int counter = 1;
	char index = object->cBegin;
	heada* nextGroup = object;
	while (nextGroup) {
		//printf("------------------------\nPrinting from group: %c\n", index);
		Object7* obj = (Object7*)nextGroup->pObject;
		while (obj) {
			//printf("Want to place object: %d) ", counter);
			//PrintSingleObject(obj);

			// Start from the top of the tree again
			pCurrentNode = pRoot;

			// Create a new node that we want to place
			Node* pNewNode = new Node;
			pNewNode->pObject = obj;
			pNewNode->pLeft = 0;
			pNewNode->pRight = 0;


			// Find where to place the node
			while (1) {
				//cout << "Looking at: *" << pCurrentNode << endl;
				ob7* tmp = (ob7*)pCurrentNode->pObject;
				if (pCurrentNode->pObject == 0) { // Handle the root exception
					pCurrentNode->pObject = obj;
					break;
				}
				else if (tmp->Code < obj->Code)
					if (pCurrentNode->pRight == 0) {
						pCurrentNode->pRight = pNewNode;
						cout << "Placing at the right branch" << endl;
						break;
					}
					else {
						pCurrentNode = pCurrentNode->pRight;
						cout << "Moving to the right branch" << endl;
					}
				else if (tmp->Code > obj->Code) {
					if (pCurrentNode->pLeft == 0) {
						pCurrentNode->pLeft = pNewNode;
						cout << "Placing at the left branch" << endl;
						break;
					}
					else {
						pCurrentNode = pCurrentNode->pLeft;
						cout << "Moving to the left branch" << endl;
					}
				}
				else {
					cout << "Error !!" << endl;
					return pRoot;
				}
			}
			// Move to the next HeaderA object
			counter++;
			obj = obj->pNext;
		}
		// Move on to the next HeaderA group
		nextGroup = nextGroup->pNext;
		if (nextGroup != 0) index = nextGroup->cBegin;
	}
	return pRoot;
}
void TreeTraversal(Node* pTree) {
	Stack* pStack = 0;
	Node *p1 = pTree, *p2;
	if (!pTree) return;
	do {
		while (p1) {
			pStack = AddToStack(pStack, p1);
			p1 = p1->pLeft;
		}
		pStack = PopFromStack(pStack, (void**)&p2);
		PrintNode(p2);
		p1 = p2->pRight;
	} while (!(!pStack && !p1));
}
void PrintNode(Node* pNode) {
	cout << "Object at the node: " << flush;
	PrintSingleObject((ob7*)pNode->pObject);
	//cout << "Left branch: " << pNode->pLeft << endl;
	//cout << "Right branch: " << pNode->pRight << endl;
}
Node* DeleteTreeNode(Node* pTree, unsigned long int Code) {
	Node* pRoot = new Node;
	pRoot = pTree;

	// Find the node
	while (1) {
		ob7* tmp = 0;
		if (!pTree) {
			// Reached the end of the tree without a match
			return pRoot;
		}
		else {
			tmp = (ob7*)pTree->pObject;
		}
		if (tmp->Code > Code) {
			// Move to the right branch
			pTree = pTree->pLeft;
		}
		else if (tmp->Code < Code) {
			pTree = pTree->pRight;
			}
		else if (tmp->Code == Code) {
			cout << "Found element: " << flush;
			PrintNode(pTree);
			if (!pTree->pLeft && !pTree->pRight) {
				// This node has no sister nodes
				pTree = 0;
				return pRoot;
			}
			else if (pTree->pLeft && pTree->pRight) {
				// This node has two sister nodes, need to merge the tree later
				return pRoot;
			}
			else {
				pTree = pTree->pLeft ? pTree->pLeft : pTree->pRight;
				return pRoot;
			}
			break;
		}
		else {
			cout << "Error !!" << endl;
			return 0;
		}
	}
}
