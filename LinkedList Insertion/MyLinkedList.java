import com.sun.security.jgss.GSSUtil;

import java.util.Scanner;

public class MyLinkedList {
    node headNode;

    static class node {
        int data;
        node next;

        public node(int d) {
            data = d;
            next = null;
        }
    }

    // case 1: Insertion at the end of the list
    public static void addElementAtEnd(MyLinkedList list, int element) {
        node new_Node = new node(element);
        new_Node.next = null;

        if (list.headNode == null) {
            list.headNode = new_Node;
        } else {
            node last_node = list.headNode;

            while (last_node.next != null) {
                last_node = last_node.next;

            }
            // insertion of the new node
            last_node.next = new_Node;
        }
    }

// case 2: Insertion of node at the beginning of the list

    public static void addElementAtBeginningOfTheList(MyLinkedList list, int element) {
        node new_node = new node(element);
        new_node.next = null;

        node ptr = list.headNode;

        list.headNode = new_node;
        list.headNode.next = ptr;
    }

    // case 3: insertion of the node at the between of the list
    public static void addElementAtTheBetweenOfList(MyLinkedList list, int index, int element) {
        node new_node = new node(element);
        new_node.next = null;
        node ptr = list.headNode;
        for (int i = 1; i <= index - 2; i++) {
            ptr = ptr.next;
        }
        new_node.next = ptr.next;
        ptr.next = new_node;
    }

    // case 4: insertion after each node
    public static void addElementAfterTheGiverNode(MyLinkedList list, int element, int prevElement) {
        node new_node = new node(element);
        new_node.next = null;
        node ptr = list.headNode;
        while (ptr.data != prevElement) {
            ptr = ptr.next;
        }
        new_node.next = ptr.next;
        ptr.next = new_node;

    }

    public static void transverse(MyLinkedList list) {
        while (list.headNode != null) {
            System.out.println(list.headNode.data);
            list.headNode = list.headNode.next;
        }
    }

    // case 1: deleting the first node
    public static void deletingFromFirstElement(MyLinkedList list) {
        if (list.headNode != null) {
            list.headNode = list.headNode.next;
        } else {
            System.out.println("List is Empty");
        }

    }

    // case 2: deleting the last element from the node
    public static void deletingFromTheLastElement(MyLinkedList list) {
        node pointer = list.headNode;
        node lastNode = list.headNode;
        while(pointer.next!=null){
            pointer=pointer.next;
        }
        while(lastNode.next!=pointer){
            lastNode=lastNode.next;
        }
        lastNode.next=null;
        if(lastNode.data==list.headNode.data){
          list.headNode=list.headNode.next;    // for the remaining last element in the list .
        }

        if(list.headNode==null){
            System.out.println("List is Empty");
        }
    }

    // case 3: deleting the node for the given element
    public static void deleteForParticularGivenElement(MyLinkedList list, int Element) {
        node pointer = list.headNode;
        node beforePointer = list.headNode;
        while (pointer != null) {
            if (pointer.data == Element) {
                System.out.println("Element found");
                break;
            }
            pointer = pointer.next;
            if (pointer == null) {
                System.out.println("Element Not Found");
                return;
            }
        }
        if (list.headNode.data == Element) {
            list.headNode = list.headNode.next; // for intial element in the linkedList
            return;
        }
        while (pointer.data != Element) {
            pointer = pointer.next;
        }
        while (beforePointer.next != pointer) {
            beforePointer = beforePointer.next;
        }
        beforePointer.next = pointer.next;

    }


    public static void main(String[] args) {
        MyLinkedList list = new MyLinkedList();
        MyLinkedList.addElementAtEnd(list, 1);
        MyLinkedList.addElementAtEnd(list, 2);
        MyLinkedList.addElementAtEnd(list, 3);
        MyLinkedList.addElementAtEnd(list, 4);
        MyLinkedList.addElementAtEnd(list, 5);
        MyLinkedList.addElementAtTheBetweenOfList(list, 2, 60);

//        MyLinkedList.addElementAtTheBetweenOfList(list, 2, 65);
//        MyLinkedList.addElementAtTheBetweenOfList(list, 2, 80);
//        MyLinkedList.addElementAtTheBetweenOfList(list, 2, 85);
//        MyLinkedList.addElementAtTheBetweenOfList(list, 2, 95);
//        MyLinkedList.deleteForParticularGivenElement(list,1);
        MyLinkedList.deletingFromTheLastElement(list);
        MyLinkedList.deletingFromTheLastElement(list);
        MyLinkedList.deletingFromTheLastElement(list);
        MyLinkedList.deletingFromTheLastElement(list);
        MyLinkedList.deletingFromTheLastElement(list);



        MyLinkedList.transverse(list);
    }
}
