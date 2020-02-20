package TABELAS;

import DAL.ConnectToDB;
import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import javax.swing.JOptionPane;

public class Evento {
    Connection connect = null;
    PreparedStatement pst = null;
    ResultSet rs = null;  
    //Statement st = null;
    
    public Evento (String user, String password) throws ClassNotFoundException {
        connect = ConnectToDB.conectToDB(user, password);
    }
    
    public void Insert (String dataString, String nome, String cpf) throws ParseException {
        // Método que insere eventos no BD
        
        String sql = "INSERT INTO evento VALUES (?,?,?);";
        int returnInsert;
        
        try {
            SimpleDateFormat formato;
            java.util.Date d;
            java.sql.Date data;
            
            formato = new SimpleDateFormat("dd/mm/yyyy");
            d = formato.parse(dataString);
            data = new java.sql.Date(d.getTime());
            
            pst = connect.prepareStatement(sql);
            //pst.setString(1, data);
            pst.setDate(1, data);
            pst.setString(2, nome);
            pst.setString(3, cpf);
            //rs = pst.executeQuery();
            returnInsert = pst.executeUpdate();
            
            JOptionPane.showMessageDialog(null, "Evento inserido!");
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        rs = null;
        pst = null; 
    }
    
    public void Delete (String data, String nome) {
        // Metodo que deleta eventos do BD
        
        String sql = "DELETE FROM evento WHERE nome = ? AND data = ?;";
        int returnDelete;
        
        try {
            pst = connect.prepareStatement(sql);
            pst.setString(1, data);
            pst.setString(2, nome);
            
            returnDelete = pst.executeUpdate();
            
            if (returnDelete == 0) {
                // Evento nao existia no BD
                JOptionPane.showMessageDialog(null, "Não existe evento com nome '" + nome +"'! e data" + data);
            }
            
            else {
                JOptionPane.showMessageDialog(null, "Evento removido!");
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
