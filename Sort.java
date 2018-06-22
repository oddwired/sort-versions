
import java.util.ArrayList;
public class Sort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String[] l = {
			"1.1.2",
			"1.0",
			"1.3.3",
			"1.0.12",
			"1.0.2",
			"2.0",
			"15.45",
			"15.09",
			"0.0",
			"1",
			"0",
			"0.0",
			"2.0.1",
			"2.1.2",
			"0.1.2",
			"0.1"
		};
		
		String[] sorted = sort(l);
		
		for(int i = 0; i < sorted.length; i++){
			System.out.println(sorted[i]);
		}

	}
	
	private static String[] sort(String[] l){
		String value;
		int j;
		for(int i = 0; i < l.length ; i++){
			value = l[i];
			j = i - 1;
			
			while(j >= 0 && greater(l[j], value)){
				l[j + 1] = l[j];
				j--;
			}
			l[j + 1] = value;
		}
		
		return l;

	}
	
	private static boolean greater(String value, String current_value){
		//find the first part
		int value_1 = getPart(value, 0),
				value_2 = getPart(value, 1),
				value_3 = getPart(value, 2);
		int current_value_1 = getPart(current_value, 0),
				current_value_2 = getPart(current_value, 1),
				current_value_3 = getPart(current_value, 2);
		
		
		
		if(value_1 > current_value_1){
			return true;
		}else if((value_1 == current_value_1) && (value_2 > current_value_2)){
			return true;
		}else if((value_1 == current_value_1) 
				&& (value_2 == current_value_2)
				&& (value_3 > current_value_3)){
			return true;
		}else if((value_1 == current_value_1) 
				&& (value_2 == current_value_2)
				&& (value_3 == current_value_3)
				&& (value.length() > current_value.length())){
			return true;
		}else{
			return false;
		}
	}
	
	private static int getPart(String value, int part){
		ArrayList<Integer> parts = new ArrayList<>();
		//int i = 0;
		for(String s : value.split("\\.", 0)){
			parts.add(Integer.parseInt(s));
		}
		
		if(parts.size() - 1< part){
			return 0;
		}
		
		return parts.get(part);
	}

}
