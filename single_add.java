 
class LinkedList {
    Node head;

    public LinkedList() 
    {
        this.head = null;
    }
    
    public void add(int data) 
    {
       Node newNode = new Node(data);
       if (head == null) {
            head = newNode;
       }
       else
       {
            Node current = head;
            while (current.next != null)
            {
                current = current.next;
            }
            current.next = newNode;
        }
    }
    
    
    
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }
    
    
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
    
     public static void main() 
     {
        LinkedList list = new LinkedList();

        // Adding elements to the linked list
        list.add(5);
        list.add(10);
        list.add(15);
        

        // Displaying the linked list elements
        System.out.println("Linked List ");
        
        list.display();
        list.insertAtEnd(105);
        System.out.println("Linked List after insertion at end :");
        list.display();
        
        System.out.println("Linked List after front insertion:");
       
        list.insertAtBeginning(789);
        list.display();
}

}





class Node {
    
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}
