class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedListOperations {
    Node head;

    // Method to insert a node at the beginning of the LinkedList
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Method to insert a node at the end of the LinkedList
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node last = head;
        while (last.next != null) {
            last = last.next;
        }
        last.next = newNode;
    }

    // Method to insert a node at the middle of the LinkedList
    public void insertAtMiddle(int data, int position) {
        Node newNode = new Node(data);
        if (position == 0) {
            newNode.next = head;
            head = newNode;
            return;
        }
        Node current = head;
        int count = 0;
        while (current != null && count < position - 1) {
            current = current.next;
            count++;
        }
        if (current == null) {
            return;
        }
        newNode.next = current.next;
        current.next = newNode;
    }

    // Method to delete a node from the beginning of the LinkedList
    public void deleteFromStart() {
        if (head != null) {
            head = head.next;
        }
    }

    // Method to delete a node from the end of the LinkedList
    public void deleteFromEnd() {
        if (head == null || head.next == null) {
            head = null;
            return;
        }
        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
    }

    // Method to delete a node from the middle of the LinkedList
    public void deleteFromMiddle(int position) {
        if (head == null) {
            return;
        }
        Node current = head;
        if (position == 0) {
            head = head.next;
            return;
        }
        int count = 0;
        while (current != null && count < position - 1) {
            current = current.next;
            count++;
        }
        if (current == null || current.next == null) {
            return;
        }
        current.next = current.next.next;
    }

    // Method to calculate the number of nodes in the LinkedList
    public int countNodes() {
        int count = 0;
        Node current = head;
        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }

    // Method to display the LinkedList elements
    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedListOperations list = new LinkedListOperations();
        
        // Insertion examples
        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);
        list.insertAtBeginning(5);
        list.insertAtMiddle(15, 2);
        
        System.out.println("LinkedList after insertions:");
        list.display(); // Displaying LinkedList
        
        // Deletion examples
        list.deleteFromStart();
        list.deleteFromEnd();
        list.deleteFromMiddle(1);
        
        System.out.println("LinkedList after deletions:");
        list.display(); // Displaying LinkedList
        
        int nodeCount = list.countNodes();
        System.out.println("Number of nodes in the LinkedList: " + nodeCount);
    }
}
