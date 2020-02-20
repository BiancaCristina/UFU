package TABELAS;

import DAL.ConnectToDB;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JOptionPane;

public class Cinema {
    Connection connect = null;
    PreparedStatement pst = null;
    ResultSet rs = null;  
    //Statement st = null;
    
    public Cinema (String user, String password) throws ClassNotFoundException {
        connect = ConnectToDB.conectToDB(user, password);
    }
    
    public void Insert (String nome, float faturamento, int tipo_comodo) {
        // Método que insere cinemas no BD

        try {        
            String sql = "INSERT INTO cinema VALUES (?,?, ?);";
            int returnInsert;
            
            pst = connect.prepareStatement(sql);
            pst.setString(1, nome);
            pst.setFloat(2, faturamento);
            pst.setInt(3, tipo_comodo);
            
            //rs = pst.executeQuery();
            returnInsert = pst.executeUpdate();
            
            JOptionPane.showMessageDialog(null, "Cinema inserido!");
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        rs = null;
        pst = null; 
    }
    
    public void Delete (String nome) {
        // Metodo que deleta cinemas do BD
        
        String sql = "DELETE FROM cinema WHERE nome = ?;";
        int returnDelete;
        
        try {
            pst = connect.prepareStatement(sql);
            pst.setString(1, nome);
            
            returnDelete = pst.executeUpdate();
            
            if (returnDelete == 0) {
                // Cinema nao existia no BD
                JOptionPane.showMessageDialog(null, "Não existe cinema com nome '" + nome +"'!");
            }
            
            else {
                JOptionPane.showMessageDialog(null, "Cinema removido!");
            }
            
        }
        
        catch (SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        rs = null;
        pst = null; 
    }
    
    public void UpdateNome (String nomeAntigo, String nomeNovo) {
        
        try {
            String sql = "UPDATE cinema SET nome = ? WHERE nome = ?;";
            int returnUpdate;
            
            pst = connect.prepareStatement(sql);
            pst.setString(1, nomeNovo);
            pst.setString(2, nomeAntigo);
            
            returnUpdate = pst.executeUpdate();
            
            if (returnUpdate == 0) {
                // Cinema nao existia no BD
                JOptionPane.showMessageDialog(null, "Não existe cinema com nome '" + nomeAntigo +"'!");
            }
            
            else {
                JOptionPane.showMessageDialog(null, "Nome do cinema atualizado de " + nomeAntigo + " para " + nomeNovo);
            }
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        pst = null;
        rs = null; 
    }
    
    public void Select (String nome) {
        /* Consulta temporaria para teste */
    }
}
