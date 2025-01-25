public class Node<T> {
    private T num;
    private Node next = null;

    public Node(T num) {
        this.num = num;
    }

    public Node(T num, Node next) {
        this.num = num;
        this.next = next;
    }

    public T getNum() {
        return num;
    }

    public void setNum(T num) {
        this.num = num;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
