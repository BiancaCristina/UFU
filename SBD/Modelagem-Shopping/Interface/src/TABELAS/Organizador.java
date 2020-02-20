package TABELAS;

import DAL.ConnectToDB;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JOptionPane;

public class Organizador {
    Connection connect = null;
    PreparedStatement pst = null;
    ResultSet rs = null;  
    //Statement st = null;
    
    public Organizador (String user, String password) throws ClassNotFoundException {
        connect = ConnectToDB.conectToDB(user, password);
    }
    
    public void Update (String cpf, String nome) {
        String sql = "UPDATE organizador SET nome = ? WHERE cpf = ?";
        int returnUpdate;
        
        try {
            pst = connect.prepareStatement(sql);
            pst.setString(1,nome);
            pst.setString(2, cpf);
           
            
            //rs = pst.executeQuery();
            returnUpdate = pst.executeUpdate();
            
            JOptionPane.showMessageDialog(null, "Organizador atualizado!");
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        rs = null;
        pst = null;         
        
        
    }
}
