public class Main {
    public static void main(String[] args) {


        Node n = new Node(2.5);
        Node n1 = new Node(3.1);
        Node n2 = new Node(10.2);
        n.setNext(n1);
        LinkedList l = new LinkedList(n);
        l.printList();

        // Append a new node
        System.out.println();
        l.append(n2);
        l.printList();

        // Append a new num
        System.out.println();
        l.append(20);
        l.printList();

        // Add in the middle
        System.out.println();
        Node n3 = new Node(30);
        l.append(n3, 2);
        l.printList();

        // Delete a node
        System.out.println();
        l.delete(2);
        l.printList();
//        System.out.println(n.getNext().getNum());
    }
}