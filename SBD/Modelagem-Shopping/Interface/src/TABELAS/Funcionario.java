package TABELAS;

import DAL.ConnectToDB;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JOptionPane;

public class Funcionario {
    Connection connect = null;
    PreparedStatement pst = null;
    ResultSet rs = null;  
    //Statement st = null;
    
    public Funcionario (String user, String password) throws ClassNotFoundException {
        connect = ConnectToDB.conectToDB(user, password);
    }
    
    public void Insert (String cpf, String nome, Float salario, String genero) {
        String sql = "INSERT INTO funcionario VALUES (?,?,?,?);";
        int returnInsert;
        
        try {
            pst = connect.prepareStatement(sql);
            pst.setString(1, cpf);
            pst.setString(2, nome);
            pst.setFloat(3, salario);
            pst.setString(4, genero);
            
            //rs = pst.executeQuery();
            returnInsert = pst.executeUpdate();
            
            JOptionPane.showMessageDialog(null, "Funcionario inserido!");
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
        
        rs = null;
        pst = null; 
    }
}
