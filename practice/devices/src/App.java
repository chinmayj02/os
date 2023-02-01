import java.util.ArrayList;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class App {
  public static void main(String[] args) {
    ArrayList<String> connectedDevices = new ArrayList<>();
    try {
      Process p = Runtime.getRuntime().exec("adb devices");
      BufferedReader input = new BufferedReader(new InputStreamReader(p.getInputStream()));
      String line;
      while ((line = input.readLine()) != null) {
        if (!line.contains("List of devices attached")) {
          connectedDevices.add(line.split("\t")[0]);
        }
      }
      input.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
    System.out.println("Connected Devices: " + connectedDevices);
  }
}

