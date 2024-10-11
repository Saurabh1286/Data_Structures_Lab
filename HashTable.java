import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class HashTable {
    final int size = 10;
    int[] table;
    int collision;

    HashTable() {
        table = new int [size];
        collision = 0;
    }
    
    void insert (int key, int index) {
        while (table[index] != 0) {
            collision = collision + 1;
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    void division (int key) {
        int index = key % size;
        insert(key,index); 
    }
    
    void multiplication (int key) {
        double a = 0.618;
        int index = (int) (size*((key*a) % 1));
        insert(key, index);
    }

    void midsquare (int key) {
        int Square = (key*key) % 10000;
        int index = Square % size;   
        insert(key, index);
    }

    void folding (int key) {
        String keyString = String.valueOf(key);
        int sum = 0;
        for(int i = 0; i < keyString.length(); i += 2){
            String part;
            if(i + 1 < keyString.length())
            {
                part = keyString.substring(i , i+2);
            }
            else
            {
                part = keyString.substring(i);
            }
            sum += Integer.parseInt(part);
        }
        int index = sum % size;
        insert(key, index);
    }

    void Display () {
        System.out.println("HashTable");
        for(int i = 0; i < table.length; i++){
            System.out.println("Index "+ i + " : " + table[i]);
        }
        System.out.println("Collision : " + collision);
    }

    public static void main(String[] args) throws IOException {
        HashTable table = new HashTable();
        System.out.print("Enter values : ");
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        int arr[] = Arrays.stream(in.readLine().replaceAll("\\s+", " ").split(" ")).mapToInt(Integer::parseInt).toArray();
        System.out.println();
        System.out.print("Division");
        for(int i:arr){
            table.division(i);
        }
        System.out.println();
        table.Display();
        HashTable table1 = new HashTable();
        System.out.println();
        System.out.println("Multiplication");
        for(int j:arr){
            
            table1.multiplication(j);
        }
        table1.Display();
        System.out.println();

        HashTable table2=new HashTable();
        System.out.println("Mid-Square");
        for(int j:arr){
            table2.midsquare(j);
        }
        table2.Display();
        System.out.println();
        HashTable table3=new HashTable();
        System.out.println("Folding");
        for(int j:arr){
            table3.folding(j);
        }
        table3.Display();
        System.out.println();
    }
}
