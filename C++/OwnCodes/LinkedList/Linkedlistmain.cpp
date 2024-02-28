#include <iostream>
#include "Linkedlist.h"

int main() {
    Node* myList = nullptr;
    Node* myList2 = nullptr;

    int choice;
    do {
        std::cout << "\nLinked List Operations Menu:\n";
        std::cout << "1. Count\n";
        std::cout << "2. GetNth\n";
        std::cout << "3. DeleteList\n";
        std::cout << "4. Pop\n";
        std::cout << "5. InsertNth\n";
        std::cout << "6. SortedInsert\n";
        std::cout << "7. InsertSort\n";
        std::cout << "8. Append\n";
        std::cout << "9. FrontBackSplit\n";
        std::cout << "10. RemoveDuplicates\n";
        std::cout << "11. MoveNode\n";
        std::cout << "12. AlternatingSplit\n";
        std::cout << "13. ShuffleMerge\n";
        std::cout << "14. SortedMerge\n";
        std::cout << "15. MergeSort\n";
        std::cout << "16. SortedIntersect\n";
        std::cout << "17. Reverse\n";
        std::cout << "18. RecursiveReverse\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int searchFor;
                std::cout << "Enter the value to count: ";
                std::cin >> searchFor;
                int count = Count(myList, searchFor);
                std::cout << "Count: " << count << std::endl;
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter the index to get the value: ";
                std::cin >> index;
                int value = GetNth(myList, index);
                std::cout << "Value at index " << index << ": " << value << std::endl;
                break;
            }
            case 3: {
                DeleteList(myList);
                std::cout << "List deleted successfully.\n";
                break;
            }
            case 4: {
                int poppedValue = Pop(myList);
                std::cout << "Popped value: " << poppedValue << std::endl;
                break;
            }
            case 5: {
                int index, data;
                std::cout << "Enter the index to insert at: ";
                std::cin >> index;
                std::cout << "Enter the data to insert: ";
                std::cin >> data;
                InsertNth(myList, index, data);
                std::cout << "Element inserted successfully.\n";
                break;
            }
            case 6: {
                int data;
                std::cout << "Enter the data to insert: ";
                std::cin >> data;
                SortedInsert(myList, new Node(data));
                std::cout << "Element inserted at the correct position.\n";
                break;
            }
            case 7: {
                InsertSort(myList);
                std::cout << "List sorted successfully.\n";
                break;
            }
            case 8: {
                Append(myList, myList2);
                std::cout << "Lists appended successfully.\n";
                break;
            }
            case 9: {
                Node* front = nullptr;
                Node* back = nullptr;
                FrontBackSplit(myList, front, back);
                std::cout << "Front List: ";
                while (front != nullptr) {
                    std::cout << front->getData() << " ";
                    front = front->getNext();
                }
                std::cout << "\nBack List: ";
                while (back != nullptr) {
                    std::cout << back->getData() << " ";
                    back = back->getNext();
                }
                std::cout << std::endl;
                break;
            }
            case 10: {
                RemoveDuplicates(myList);
                std::cout << "Duplicates removed successfully.\n";
                break;
            }
            case 11: {
                Node* destList = nullptr;
                MoveNode(destList, myList);
                std::cout << "Node moved to the destination list.\n";
                break;
            }
            case 12: {
                Node* list1 = nullptr;
                Node* list2 = nullptr;
                AlternatingSplit(myList, list1, list2);
                std::cout << "List 1: ";
                while (list1 != nullptr) {
                    std::cout << list1->getData() << " ";
                    list1 = list1->getNext();
                }
                std::cout << "\nList 2: ";
                while (list2 != nullptr) {
                    std::cout << list2->getData() << " ";
                    list2 = list2->getNext();
                }
                std::cout << std::endl;
                break;
            }
            case 13: {
                Node* shuffledList = ShuffleMerge(myList, myList2);
                std::cout << "Shuffled merged list: ";
                while (shuffledList != nullptr) {
                    std::cout << shuffledList->getData() << " ";
                    shuffledList = shuffledList->getNext();
                }
                std::cout << std::endl;
                break;
            }
            case 14: {
                Node* sortedMergedList = SortedMerge(myList, myList2);
                std::cout << "Sorted merged list: ";
                while (sortedMergedList != nullptr) {
                    std::cout << sortedMergedList->getData() << " ";
                    sortedMergedList = sortedMergedList->getNext();
                }
                std::cout << std::endl;
                break;
            }
            case 15: {
                MergeSort(myList);
                std::cout << "List sorted using merge sort.\n";
                break;
            }
            case 16: {
                Node* intersectedList = SortedIntersect(myList, myList2);
                std::cout << "Sorted intersection list: ";
                while (intersectedList != nullptr) {
                    std::cout << intersectedList->getData() << " ";
                    intersectedList = intersectedList->getNext();
                }
                std::cout << std::endl;
                break;
            }
            case 17: {
                Reverse(myList);
                std::cout << "List reversed successfully.\n";
                break;
            }
            case 18: {
                RecursiveReverse(myList);
                std::cout << "List recursively reversed successfully.\n";
                break;
            }
            case 0: {
                std::cout << "Exiting...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }

    } while (choice != 0);

    return 0;
}

