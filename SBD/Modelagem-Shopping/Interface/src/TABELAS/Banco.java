package TABELAS;

import DAL.ConnectToDB;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JOptionPane;

public class Banco {
    Connection connect = null;
    PreparedStatement pst = null;
    ResultSet rs = null;  
    //Statement st = null;
    
    public Banco (String user, String password) throws ClassNotFoundException {
        connect = ConnectToDB.conectToDB(user, password);
    }
    
    public void Insert (String nome, int localizacao) {
        // Método que insere bancos no BD
        
        String sql = "INSERT INTO banco VALUES (?,?);";
        int returnInsert;
        
        try {
            pst = connect.prepareStatement(sql);
            pst.setString(1, nome);
            pst.setInt(2, localizacao);
            
            //rs = pst.executeQuery();
            returnInsert = pst.executeUpdate();
            
            JOptionPane.showMessageDialog(null, "Banco inserido!");
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        rs = null;
        pst = null; 
    }
    
    public void Delete (String nome) {
        // Metodo que deleta bancos do BD
        
        String sql = "DELETE FROM banco WHERE nome = ?;";
        int returnDelete;
        
        try {
            pst = connect.prepareStatement(sql);
            pst.setString(1, nome);
            
            returnDelete = pst.executeUpdate();
            
            if (returnDelete == 0) {
                // Banco nao existia no BD
                JOptionPane.showMessageDialog(null, "Não existe banco com nome '" + nome +"'!");
            }
            
            else {
                JOptionPane.showMessageDialog(null, "Banco removido!");
            }
            
        }
        
        catch (SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        rs = null;
        pst = null; 
    }
    
    public void Select (String nome) {
        /* Consulta temporaria para teste */
    }
}
