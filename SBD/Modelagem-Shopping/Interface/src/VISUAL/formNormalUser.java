package VISUAL;

import DAL.ConnectToDB;
import VISUAL.VISUAL_NORMAL.formOutros;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class formNormalUser extends javax.swing.JFrame {
    String user;
    String password;
    Connection connect = null;
    PreparedStatement pst = null;
    ResultSet rs = null; 
    
    public formNormalUser(String user, String password) {
        initComponents();
        cogumelo1.setVisible(false);
        cogumelo3.setVisible(false);
        cogumelo4.setVisible(false);
        cogumelo2.setVisible(false);
        cogumeloOutros.setVisible(false);
        
        this.setLocationRelativeTo(null);       // Faz com que o JFrame fique no centro da tela
        
        try {
            connect = ConnectToDB.conectToDB(user, password);
            this.user = user;
            this.password = password; 
            //this.setExtendedState(WIDTH);
        } 
        
        catch (ClassNotFoundException ex) {
            Logger.getLogger(formNormalUser.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton13 = new javax.swing.JButton();
        cogumelo = new javax.swing.JLabel();
        consulta1 = new javax.swing.JButton();
        consulta2 = new javax.swing.JButton();
        consulta3 = new javax.swing.JButton();
        consulta4 = new javax.swing.JButton();
        outros = new javax.swing.JButton();
        cogumelo1 = new javax.swing.JLabel();
        cogumelo3 = new javax.swing.JLabel();
        cogumelo4 = new javax.swing.JLabel();
        cogumelo2 = new javax.swing.JLabel();
        cogumeloOutros = new javax.swing.JLabel();

        jButton13.setText("Consulta 1");

        cogumelo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        consulta1.setText("Consulta 1");
        consulta1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                consulta1MouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                consulta1MouseEntered(evt);
            }
        });
        consulta1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                consulta1ActionPerformed(evt);
            }
        });

        consulta2.setText("Consulta 2");
        consulta2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                consulta2MouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                consulta2MouseEntered(evt);
            }
        });
        consulta2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                consulta2ActionPerformed(evt);
            }
        });

        consulta3.setText("Consulta 3");
        consulta3.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                consulta3MouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                consulta3MouseEntered(evt);
            }
        });
        consulta3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                consulta3ActionPerformed(evt);
            }
        });

        consulta4.setText("Consulta 4");
        consulta4.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                consulta4MouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                consulta4MouseEntered(evt);
            }
        });
        consulta4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                consulta4ActionPerformed(evt);
            }
        });

        outros.setText("Outros");
        outros.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                outrosMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                outrosMouseEntered(evt);
            }
        });
        outros.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                outrosActionPerformed(evt);
            }
        });

        cogumelo1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumeloOutros.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(82, 82, 82)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(cogumelo1)
                        .addComponent(cogumelo3)
                        .addComponent(cogumelo4, javax.swing.GroupLayout.Alignment.TRAILING)
                        .addComponent(cogumelo2, javax.swing.GroupLayout.Alignment.TRAILING))
                    .addComponent(cogumeloOutros))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(consulta3, javax.swing.GroupLayout.DEFAULT_SIZE, 115, Short.MAX_VALUE)
                    .addComponent(consulta4, javax.swing.GroupLayout.DEFAULT_SIZE, 115, Short.MAX_VALUE)
                    .addComponent(consulta2, javax.swing.GroupLayout.DEFAULT_SIZE, 115, Short.MAX_VALUE)
                    .addComponent(consulta1, javax.swing.GroupLayout.DEFAULT_SIZE, 115, Short.MAX_VALUE)
                    .addComponent(outros, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(132, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(consulta1)
                    .addComponent(cogumelo1))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(consulta2)
                    .addComponent(cogumelo2))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(consulta3)
                    .addComponent(cogumelo3))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(consulta4)
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(outros)
                            .addComponent(cogumeloOutros)))
                    .addComponent(cogumelo4))
                .addContainerGap(50, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void consulta2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_consulta2ActionPerformed
        // TODO add your handling code here:
        String sql;
     
        JOptionPane.showMessageDialog(null, "Consulta que exibe o nome do funcionário que não seja cozinheiro, empregado ou administrador.");
        
        sql = "SELECT DISTINCT\n" +
"	f.nome\n" +
"\n" +
"FROM\n" +
"	funcionario AS f\n" +
"	\n" +
"WHERE\n" +
"	f.cpf NOT IN (SELECT cozinheiro.cpf FROM cozinheiro) AND\n" +
"	f.cpf NOT IN (SELECT emp_corporativo.cpf FROM emp_corporativo) AND\n" +
"	f.cpf NOT IN (SELECT administrador.cpf FROM administrador); ";
        
        JOptionPane.showMessageDialog(null, sql);
        
        try {
          String resultado = "Nome do funcionário: \n"; 
          pst = connect.prepareStatement(sql);
          rs = pst.executeQuery();
          
          while (rs.next()) {
              resultado += rs.getString("nome") + "\n"; 
          }
          
          JOptionPane.showMessageDialog(null, resultado);
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
    }//GEN-LAST:event_consulta2ActionPerformed

    private void consulta1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_consulta1ActionPerformed
        // TODO add your handling code here:
        String sql;
     
        JOptionPane.showMessageDialog(null, "Consulta que exibe o nome do locatário que aluga menos tipos de cômodo");
        
        sql = "SELECT \n" +
"	lo.nome\n" +
"	\n" +
"FROM \n" +
"	aluga al INNER JOIN locatario lo ON al.cnpj = lo.cnpj\n" +
"	\n" +
"GROUP BY lo.nome\n" +
"\n" +
"HAVING COUNT(*) <= ALL	(\n" +
"				SELECT COUNT(aluga.cnpj) \n" +
"				FROM aluga \n" +
"				GROUP BY aluga.cnpj\n" +
"			);";
        
        JOptionPane.showMessageDialog(null, sql);
        
        try {
          String resultado = "Nome do locatário: \n"; 
          pst = connect.prepareStatement(sql);
          rs = pst.executeQuery();
          
          while (rs.next()) {
              resultado += rs.getString("nome") + "\n"; 
          }
          
          JOptionPane.showMessageDialog(null, resultado);
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
    }//GEN-LAST:event_consulta1ActionPerformed

    private void consulta3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_consulta3ActionPerformed
        // TODO add your handling code here:
        String sql;
     
        JOptionPane.showMessageDialog(null, "Consulta que exibe o nome do locatário mais rico");
        
        sql = "SELECT \n" +
"	lo.nome\n" +
"	\n" +
"FROM\n" +
"	locatario AS lo\n" +
"	\n" +
"WHERE\n" +
"	lo.renda_anual >= 	(\n" +
"					SELECT MAX(lo.renda_anual)\n" +
"					FROM locatario AS lo\n" +
"				);";
        
        JOptionPane.showMessageDialog(null, sql);
        
        try {
          String resultado = "Nome do funcionário: \n"; 
          pst = connect.prepareStatement(sql);
          rs = pst.executeQuery();
          
          while (rs.next()) {
              resultado += rs.getString("nome") + "\n"; 
          }
          
          JOptionPane.showMessageDialog(null, resultado);
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
    }//GEN-LAST:event_consulta3ActionPerformed

    private void consulta4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_consulta4ActionPerformed
        // TODO add your handling code here:
        String sql;
     
        JOptionPane.showMessageDialog(null, "Consulta que exibe quais funcionários possuem salário maior que a média de todos os salários.");
        
        sql = "SELECT \n" +
"	f.nome\n" +
"	\n" +
"FROM\n" +
"	funcionario AS f\n" +
"	\n" +
"GROUP BY f.nome, f,salario\n" +
"HAVING f.salario > (\n" +
"			SELECT AVG(funcionario.salario)\n" +
"			FROM funcionario\n" +
"		   ); ";
        
        JOptionPane.showMessageDialog(null, sql);
        
        try {
          String resultado = "Nome do funcionário: \n"; 
          pst = connect.prepareStatement(sql);
          rs = pst.executeQuery();
          
          while (rs.next()) {
              resultado += rs.getString("nome") + "\n"; 
          }
          
          JOptionPane.showMessageDialog(null, resultado);
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }        
    }//GEN-LAST:event_consulta4ActionPerformed

    private void outrosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_outrosActionPerformed
        // TODO add your handling code here:
        formOutros form = new formOutros(this.user, this.password);
        dispose();
        
        form.setVisible(true);
        
    }//GEN-LAST:event_outrosActionPerformed

    private void consulta1MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_consulta1MouseEntered
        // TODO add your handling code here:
        cogumelo1.setVisible(true);
    }//GEN-LAST:event_consulta1MouseEntered

    private void consulta1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_consulta1MouseExited
        // TODO add your handling code here:
        cogumelo1.setVisible(false);
    }//GEN-LAST:event_consulta1MouseExited

    private void outrosMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_outrosMouseEntered
        // TODO add your handling code here:
        cogumeloOutros.setVisible(true);
    }//GEN-LAST:event_outrosMouseEntered

    private void outrosMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_outrosMouseExited
        // TODO add your handling code here:
        cogumeloOutros.setVisible(false);
    }//GEN-LAST:event_outrosMouseExited

    private void consulta2MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_consulta2MouseEntered
        // TODO add your handling code here:
        cogumelo2.setVisible(true);
    }//GEN-LAST:event_consulta2MouseEntered

    private void consulta2MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_consulta2MouseExited
        // TODO add your handling code here:
        cogumelo2.setVisible(false);
    }//GEN-LAST:event_consulta2MouseExited

    private void consulta3MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_consulta3MouseEntered
        // TODO add your handling code here:
        cogumelo3.setVisible(true);
    }//GEN-LAST:event_consulta3MouseEntered

    private void consulta3MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_consulta3MouseExited
        // TODO add your handling code here:
        cogumelo3.setVisible(false);
    }//GEN-LAST:event_consulta3MouseExited

    private void consulta4MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_consulta4MouseEntered
        // TODO add your handling code here:
        cogumelo4.setVisible(true);
    }//GEN-LAST:event_consulta4MouseEntered

    private void consulta4MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_consulta4MouseExited
        // TODO add your handling code here:
        cogumelo4.setVisible(false);
    }//GEN-LAST:event_consulta4MouseExited

    
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //formNormalUser form = new formNormalUser();
                //new formNormalUser(this.user, this.password).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel cogumelo;
    private javax.swing.JLabel cogumelo1;
    private javax.swing.JLabel cogumelo2;
    private javax.swing.JLabel cogumelo3;
    private javax.swing.JLabel cogumelo4;
    private javax.swing.JLabel cogumeloOutros;
    private javax.swing.JButton consulta1;
    private javax.swing.JButton consulta2;
    private javax.swing.JButton consulta3;
    private javax.swing.JButton consulta4;
    private javax.swing.JButton jButton13;
    private javax.swing.JButton outros;
    // End of variables declaration//GEN-END:variables
}
