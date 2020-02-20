 
package VISUAL;

import java.sql.*;
import DAL.ConnectToDB;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class formLogin extends javax.swing.JFrame {
    String user;
    String password;
     
    public formLogin() throws ClassNotFoundException {
        initComponents();
        this.setLocationRelativeTo(null);       // Faz com que o JFrame fique no centro da tela 
        this.setSize(300,250);
        //this.setExtendedState(JFrame.MAXIMIZED_BOTH);
        cogumelo.setVisible(false);
    }
    
    public void Logar() {
        boolean resultado;
        ResultSet rs1;
        PreparedStatement pst1;
        
        try {
            Connection connect = null;
            PreparedStatement pst = null;
            ResultSet rs = null;
            
            String user;
            String password; 
            boolean flag = false; // Define se eh cadastro ou login
            
            user = userField.getText();
            password = passwordField.getText();
            
            this.user = user;
            this.password = password; 
            
            try {
                connect = ConnectToDB.conectToDB(user,password);
                flag = true; 
            } 
            
            catch (ClassNotFoundException ex) {
                Logger.getLogger(formLogin.class.getName()).log(Level.SEVERE, null, ex);
                System.exit(-1); 
            }
            
            pst = connect.prepareStatement("SELECT fazer_login (?)");
            pst.setString(1, userField.getText());
            rs = pst.executeQuery(); 
            
            if (flag != false) {
                if (rs.next()) {
                    // Caso exista esse usuario e senha no banco de dados
                    resultado = rs.getBoolean(1);

                    if (resultado == true) {
                        boolean permissao; 

                        JOptionPane.showMessageDialog(null, "Bem vindo!");  

                        pst1 = connect.prepareStatement("SELECT verifica_permissao();");
                        rs1 = pst1.executeQuery(); 

                        if (rs1.next()) {
                            // Caso a funcao de verificar permissao ocorra com sucesso

                            permissao = rs1.getBoolean(1);

                            if (permissao == true) {
                                // Entao eh admin_user
                                formAdminUser formAdmin = new formAdminUser(user, password);

                                formAdmin.setVisible(true);
                            }

                            else {
                                // Entao eh normal_user
                                formNormalUser formNormal = new formNormalUser(user, password);

                                formNormal.setVisible(true);
                            }
                        }

                        else {
                            // Caso haja algum problema na verificao de permissao
                            JOptionPane.showMessageDialog(null, "Problema ao autorizar usuário!");
                        }

                        dispose();  // Fecha janela de login
                    }

                    else {
                        // Caso a funcao de login retorne false
                        JOptionPane.showMessageDialog(null, "Usuario e senha invalidos!");
                    }
                }

                else {
                    // Caso nao exista no banco de dados
                    JOptionPane.showMessageDialog(null, "Usuario e senha invalidos!");
                }
            
            }
            
            rs = null; 
        }
        
        catch(SQLException error) {
            JOptionPane.showMessageDialog(null, error);
        }
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        userField = new javax.swing.JTextField();
        entrar = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        passwordField = new javax.swing.JPasswordField();
        cogumelo = new javax.swing.JLabel();

        jButton1.setText("jButton1");

        jLabel3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/fundo-mario.png"))); // NOI18N

        jLabel4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/fundo-mario.png"))); // NOI18N

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(200, 100));

        jLabel1.setText("Usuário:");

        userField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                userFieldActionPerformed(evt);
            }
        });

        entrar.setText("Entrar");
        entrar.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                entrarMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                entrarMouseEntered(evt);
            }
        });
        entrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                entrarActionPerformed(evt);
            }
        });

        jLabel2.setText("Senha:");

        cogumelo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(32, 32, 32)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(userField, javax.swing.GroupLayout.PREFERRED_SIZE, 169, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel2)
                                .addGap(0, 0, Short.MAX_VALUE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGap(0, 0, Short.MAX_VALUE)
                                .addComponent(cogumelo)))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(entrar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(passwordField, javax.swing.GroupLayout.DEFAULT_SIZE, 169, Short.MAX_VALUE))))
                .addGap(12, 12, 12))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(46, 46, 46)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(userField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(19, 19, 19)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(passwordField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(cogumelo)
                    .addComponent(entrar))
                .addContainerGap(22, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void userFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_userFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_userFieldActionPerformed

    private void entrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_entrarActionPerformed
        // Metodo para o botao "Entrar" chamar o metodo "Logar"
        Logar();
        
    }//GEN-LAST:event_entrarActionPerformed

    private void entrarMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_entrarMouseEntered
        // TODO add your handling code here:
        // Passar o mouse
        cogumelo.setVisible(true);
    
    }//GEN-LAST:event_entrarMouseEntered

    private void entrarMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_entrarMouseExited
        // TODO add your handling code here:
        cogumelo.setVisible(false);
    }//GEN-LAST:event_entrarMouseExited

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    new formLogin().setVisible(true);
                } 
                
                catch (ClassNotFoundException ex) {
                    Logger.getLogger(formLogin.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel cogumelo;
    private javax.swing.JButton entrar;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JPasswordField passwordField;
    private javax.swing.JTextField userField;
    // End of variables declaration//GEN-END:variables
}
