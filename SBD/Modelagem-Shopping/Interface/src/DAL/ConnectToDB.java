package DAL;

import java.sql.*; 
import javax.swing.JOptionPane;

public class ConnectToDB {
    // Classe que conecta a aplicacao ao banco de dados
    
    private static final String url = "jdbc:postgresql://localhost:5432/postgres?currentSchema=shopping";
    
    public static Connection conectToDB(String user, String password) throws ClassNotFoundException {    
        try {
            Class.forName("org.postgresql.Driver");
            Connection connect = DriverManager.getConnection(url, user, password);
            
            //JOptionPane.showMessageDialog(null, "Conectado ao DB com sucesso! ");
            return connect; 
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
            
            return null; 
        }
    }
}
