import java.util.Scanner;

class Node {
    
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        this.left = this.right = null;
    }    
}

public class Binary_Search_Tree {

    Node root;

    Binary_Search_Tree() {
        root = null;
    }
    
    void insert (int val) {
        if (root == null) {
            root = new Node(val);
            return;
        }

        insert_priv(val, this.root);
    }

    private void insert_priv (int val, Node root) {
        if (val < root.data) {
            if (root.left == null) {
                root.left = new Node(val);
            }
            else {
                insert_priv(val, root.left);
            }
        }
        else if (val > root.data) {
            if (root.right == null) {
                root.right = new Node(val);
            }
            else {
                insert_priv(val, root.right);
            }
        }
    }

    boolean search (int val) {
        if (root == null) {
            System.out.println("List is Empty");
            return false;
        }
        
        boolean flag = search_priv(val,root) != null;
        
        return flag;
    }

    Node search_priv (int val, Node root) {
        if (root == null) {
            return root;
        }

        if (root.data == val) {
            return root;
        }

        if (val < root.data) {
            return search_priv(val, root.left);
        }
        
        else {
            return search_priv(val, root.right);
        }
    }

    void inorder() {
        inOrder_priv (root);
    }

    private void inOrder_priv (Node root) {
        if (root == null) {
            return;
        }

        inOrder_priv(root.left);

        System.out.print(root.data + " ");

        inOrder_priv(root.right);
    }
    
    void preOrder() {
        preOrder_priv(root);
    } 

    private void preOrder_priv(Node root) {
        if (root == null) {
            return;
        }

        System.out.print(root.data + " ");
        
        preOrder_priv(root.left);

        preOrder_priv(root.right);
    }

    void postOrder() {
        postOrder_priv(root);
    }

    private void postOrder_priv (Node root) {
        if (root == null) {
            return;
        }

        postOrder_priv(root.left);

        postOrder_priv(root.right);
        
        System.out.print(root.data + " ");
    }
    
    boolean delete (int val) {
        if (root == null) {
            System.out.println("List is Empty");
            return false;
        }

        boolean flag = delete_priv (val, root) != null;

        return flag;
    }

    private Node delete_priv (int val, Node root) {
        if (root == null) {
            return root;
        }

        if (val < root.data) {
            root.left = delete_priv(val, root.left);
        }
        else if (val > root.data) {
            root.right = delete_priv(val, root.right);
        }
        else {
            if (root.left == null) {
                return root.right;
            }
            if (root.right == null) {
                return root.left;
            }
            Node curr = root;
            while (curr.left != null) {
                curr = curr.left;
            }
            root.data = curr.data;
            root.right = delete_priv(root.data, root.right);
        }
        return root;
    }

    public static void main(String[] args) {
        int opt;
        Binary_Search_Tree bst = new Binary_Search_Tree();
        try (Scanner sc = new Scanner(System.in)) {
            do{
                System.out.println("\nBinary Search Tree Menu : 1. Insert\t2. Delete\t3. Search\t4. Display\t5. Exit");
                System.out.println("===============================================================================================");
                System.out.print("Enter your choice : ");
                opt = sc.nextInt();
                switch(opt){
                    case 1 -> {
                        int data;
                        System.out.print("\nEnter number : ");
                        data = sc.nextInt();
                        bst.insert(data);
                    }
                        
                    case 2 -> {
                        System.out.print("\nEnter delete element: ");
                        int delkey = sc.nextInt();
                        boolean delFlag = bst.delete(delkey);
                        if (delFlag) {
                            System.out.println("Element deleted!");
                            break;
                        }
                        System.out.println("Element not found");
                    }
                        
                    case 3 -> {
                        System.out.print("\nEnter Search element: ");
                        int src = sc.nextInt();
                        boolean flag = bst.search(src);
                        if (!flag) {
                            System.out.println("Element not found!");
                            break;
                        }
                        System.out.println("Element found");
                    }
                        
                    case 4 -> {
                        System.out.println("\nDisplay Menu : 1. Inorder\t2. PostOrder\t3. PreOrder");
                        System.out.println("===========================================================");
                        System.out.print("Enter choice : ");
                        int c = sc.nextInt();
                        switch(c){
                            case 1 -> {
                                bst.inorder();
                                System.out.print("\n");
                        }
                            case 2 -> {
                                bst.postOrder();
                                System.out.print("\n");
                        }
                                
                            case 3 -> {
                                bst.preOrder();
                                System.out.print("\n");
                        }
                        }
                    }
                    case 5 -> System.out.println("\nEnd of Program !!");
                }
            }while(opt != 5);
        }
    }
}