import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Validation {
	public static void main(String[] args) {		
		String fileName1 = args[0]; 
		String fileName2 = args[1];
		String file1 = loadFile(fileName1);
		String file2 = loadFile(fileName2);
		check(file1, file2);
	}
	
	public static String loadFile(String name) {
		InputStream Stream = Validation.class.getResourceAsStream("/" + name);
		if (Stream == null) {
			try {
				File f = new File(name);
				Stream = new FileInputStream(name);
			} catch (IOException e) {
				System.out.println("file not found");
				System.exit(0);
			}
		}
		BufferedReader reader = new BufferedReader(new InputStreamReader(Stream));
		try {
			StringBuilder builder = new StringBuilder();
			String line = reader.readLine();
			while(line != null) {
				builder.append(line);
				builder.append("\n");
				line = reader.readLine();
			}
			return builder.toString();
		}
		catch(IOException e) {
			e.printStackTrace();
			System.out.println("file not found");
			System.exit(0);
		}
		return null;
	}
	
	public static void check(String file1, String file2) {
		int size1 = file1.length();
		int size2 = file2.length();
		int i = 0;
		int j = 0;
		int length = 0;
		boolean flag = false;
		Pattern p1 = Pattern.compile("[\t\n\r¥s ]");
		Pattern p3 = Pattern.compile("[tnr]");
		if (size1 < size2) {
			length = size1;
			flag = true;
		}
		else {
			length = size2;
		}
		if (flag) {
			while(i < length) {
				Character char1 = file1.charAt(i);
				Character char2 = file2.charAt(j);
				String str2 = file2.substring(j, j+1);
				if (char1.equals('\\')) {
					char1 = file1.charAt(i + 1);
					if (char1.equals('\\')) {
						String str1 = file1.substring(i+2, i+3);
						Matcher m13 = p3.matcher(str1);
						if (m13.find()) {
							i+= 3;
						}
						else {
							if (str2.equals("\\")) {
								i+=2;
								j++;
							}
							else {
								System.out.println("error");
								System.out.println("file1:" + file1.substring(i, i+10));
								System.out.println("file2:" + file2.substring(j, j+10));
								System.exit(0);
							}
						}
					}
					else {
						String str1 = file1.substring(i+1, i+2);
						Matcher m13 = p3.matcher(str1);
						if (m13.find()) {
							i+= 2;
						}
						else if (str1.equals(str2)) {
							i+=2;
							j++;
						}
						else {
							System.out.println("error");
							System.out.println("file1:" + file1.substring(i, i+10));
							System.out.println("file2:" + file2.substring(j, j+10));
							System.exit(0);
						}
					}
				}
				else if (str2.equals("\\")) {
					str2 = file2.substring(j+1, j+2);
					Matcher m2 = p3.matcher(str2);
					if (m2.find()) {
						j += 2;
					}
					else {
						System.out.println("error");
						System.out.println("file1:" + file1.substring(i, i+10));
						System.out.println("file2:" + file2.substring(j, j+10));
						System.exit(0);
					}
				}
				else if (char1.equals(char2)) {
					i++;
					j++;
				}
				else {
					String str1 = file1.substring(i, i+1);
					Matcher m1 = p1.matcher(str1);
					if (m1.find()) {
						i++;
					}
					else {
						if (str1.equals("\\")) {
							str1 = file1.substring(i+1, i+2);
							Matcher m13 = p3.matcher(str1);
							if (m13.find()) {
								i+= 1;
							}
						}
						else {
							str2 = file2.substring(j, j+1);
							Matcher m2 = p1.matcher(str2);
							if (m2.find()) {
								j++;
							}
							else {
								str1 = file1.substring(i, i+4);
								str2 = file2.substring(j, j+5);
								if (str1.equals("Text") && str2.equals("empty")) {
									i += 4;
									j += 5;
								}
								else {
									System.out.println("file1:" + file1.substring(i-10, i+10));
									System.out.println("file2:" + file2.substring(j-10, j+10));
									System.exit(0);
								}
							}
						}
					}
				}
			}
			System.out.println("file1 == file2");
		}
		else {
			while(j < length) {
				Character char1 = file1.charAt(i);
				Character char2 = file2.charAt(j);
				if (char1.equals(char2)) {
					i++;
					j++;
				}
				else {
					String str1 = file1.substring(i, i+1);
					Matcher m = p1.matcher(str1);
					if (m.find()) {
						i++;
					}
					else {
						if (str1.equals("\\")) {
							str1 = file1.substring(i+1, i+2);
							Matcher m13 = p3.matcher(str1);
							if (m13.find()) {
								i+= 2;
							}
						}
						else {
							String str2 = file2.substring(j, j+1);
							Matcher m2 = p1.matcher(str2);
							if (m2.find()) {
								j++;
							}
							else {
								System.out.println("file1:" + file1.substring(i, i+10));
								System.out.println("file2:" + file2.substring(j, j+10));
								System.exit(0);
							}
						}
					}
				}
			}
			System.out.println("file1 == file2");
		}
	}
}
