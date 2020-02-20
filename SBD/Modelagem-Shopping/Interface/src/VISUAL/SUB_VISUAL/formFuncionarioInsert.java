package VISUAL.SUB_VISUAL;

import TABELAS.Funcionario;
import java.util.logging.Level;
import java.util.logging.Logger;

public class formFuncionarioInsert extends javax.swing.JFrame {
    String user;
    String password;
    
    public formFuncionarioInsert(String user, String password) {
        this.user = user;
        this.password = password;
        
        initComponents();
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        cpfFuncionario = new javax.swing.JTextField();
        salarioFuncionario = new javax.swing.JTextField();
        generoFuncionario = new javax.swing.JTextField();
        nomeFuncionario = new javax.swing.JTextField();
        inserirFuncionario = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("CPF:");

        jLabel2.setText("Nome:");

        jLabel3.setText("Salário:");

        jLabel4.setText("Gênero:");

        cpfFuncionario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cpfFuncionarioActionPerformed(evt);
            }
        });

        salarioFuncionario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                salarioFuncionarioActionPerformed(evt);
            }
        });

        generoFuncionario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                generoFuncionarioActionPerformed(evt);
            }
        });

        nomeFuncionario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                nomeFuncionarioActionPerformed(evt);
            }
        });

        inserirFuncionario.setText("Inserir");
        inserirFuncionario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                inserirFuncionarioActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                            .addComponent(jLabel1)
                            .addGap(27, 27, 27))
                        .addGroup(layout.createSequentialGroup()
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jLabel3)
                                .addComponent(jLabel4))
                            .addGap(18, 18, 18)))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addGap(18, 18, 18)))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(inserirFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(nomeFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(cpfFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(generoFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(salarioFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, 266, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(44, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(cpfFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel2)
                    .addComponent(nomeFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(30, 30, 30)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(salarioFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel3))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel4)
                    .addComponent(generoFuncionario, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(inserirFuncionario)
                .addContainerGap(41, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void cpfFuncionarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cpfFuncionarioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_cpfFuncionarioActionPerformed

    private void salarioFuncionarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_salarioFuncionarioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_salarioFuncionarioActionPerformed

    private void generoFuncionarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_generoFuncionarioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_generoFuncionarioActionPerformed

    private void nomeFuncionarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_nomeFuncionarioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_nomeFuncionarioActionPerformed

    private void inserirFuncionarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_inserirFuncionarioActionPerformed
        // TODO add your handling code here:
    try {
            Funcionario funcionario = new Funcionario(this.user, this.password); 
            Float salario;
            
            salario = Float.parseFloat(salarioFuncionario.getText());
                   
            funcionario.Insert(cpfFuncionario.getText(), nomeFuncionario.getText(), salario, generoFuncionario.getText());
            dispose();
        } 
        
    catch (ClassNotFoundException ex) {
            Logger.getLogger(formBancoInsert.class.getName()).log(Level.SEVERE, null, ex);
        }  
    }//GEN-LAST:event_inserirFuncionarioActionPerformed

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new formFuncionarioInsert().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField cpfFuncionario;
    private javax.swing.JTextField generoFuncionario;
    private javax.swing.JButton inserirFuncionario;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JTextField nomeFuncionario;
    private javax.swing.JTextField salarioFuncionario;
    // End of variables declaration//GEN-END:variables
}
