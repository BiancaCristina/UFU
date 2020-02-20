package TABELAS;

import DAL.ConnectToDB;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JOptionPane;

public class TipoComodo {
    Connection connect = null;
    PreparedStatement pst = null;
    ResultSet rs = null;  
    //Statement st = null;
    
    public TipoComodo (String user, String password) throws ClassNotFoundException {
        connect = ConnectToDB.conectToDB(user, password);
    }
    
    public void Delete (Integer numero_identificador) {
        String sql = "DELETE FROM tipo_comodo WHERE numero_identificador = ?";
        int returnDelete; 
                
        try {
            pst = connect.prepareStatement(sql);
            pst.setInt(1,numero_identificador);

            //rs = pst.executeQuery();
            returnDelete = pst.executeUpdate();
            
            JOptionPane.showMessageDialog(null, "Tipo cômodo removido!");
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        rs = null;
        pst = null;
        
    }
    
}
