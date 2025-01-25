public class LinkedList<T> {
    Node head = null;

    public LinkedList(Node head) {
        this.head = head;
    }

    void append(Node newNode) {
        Node dummy = head;
        while (dummy.getNext() != null){
            dummy = dummy.getNext();
        }

        dummy.setNext(newNode);
    }

    void append(int x){
        Node dummy = head;
        Node newNode = new Node(x);
        while (dummy.getNext() != null){
            dummy = dummy.getNext();
        }

        dummy.setNext(newNode);
    }

    void append(Node newNode, int index){
        Node dummy = head;
        for(int i=0; i<index; i++){
            dummy = dummy.getNext();
        }
        newNode.setNext(dummy.getNext());
        dummy.setNext(newNode);
    }

    void delete(int index){
        Node dummy = head;
        for(int i=0; i<index; i++){
            dummy = dummy.getNext();
        }
        dummy.setNext(dummy.getNext().getNext());
    }

    void printList(){
        Node dummy = head;
        while (dummy != null){
            System.out.println(dummy.getNum());
            dummy = dummy.getNext();
        }
    }
}
