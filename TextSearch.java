import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;
 

//Function that scans document for word/pattern 
 
public class TextSearch {
	public static void main(String[] args) throws FileNotFoundException {
		//Uploading document 
		String dsnname;
		dsnname="war_peace.txt";
		File myfile = new File("src/data/"+ dsnname);

		//Buffering through document searching for pattern 
		Scanner input = new Scanner(myfile);
		input.useDelimiter("//Z");
		 String buffer = input.next();
		 int comparisons=0;
		 String pattern= "educated";
		 char cpattern, ctext;
		 for (int i = 0; i<buffer.length();i++) {
			ctext = buffer.charAt(i);
			cpattern = pattern.charAt(i);
			if (ctext==cpattern) {comparisons++;
		 }
		 
		//Output 
	    System.out.println("Book: " + dsnname + " Length: " + buffer.length());
	    System.out.println("Pattern: " + pattern);
	    System.out.println("Comparisons: " + comparisons);	 
	}
}
