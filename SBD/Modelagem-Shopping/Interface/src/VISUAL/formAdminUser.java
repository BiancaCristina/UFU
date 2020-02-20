package VISUAL;

import VISUAL.VISUAL_ADMIN.formBanco;
import VISUAL.VISUAL_ADMIN.formCinema;
import VISUAL.VISUAL_ADMIN.formEvento;

public class formAdminUser extends javax.swing.JFrame {    
    String user;
    String password;
    
    public formAdminUser(String user, String password) {
        this.user = user;
        this.password = password;
        
        initComponents();
        cogumelo1.setVisible(false);
        cogumelo2.setVisible(false);
        cogumelo3.setVisible(false);
        
        this.setLocationRelativeTo(null);       // Faz com que o JFrame fique no centro da tela
        //this.setExtendedState(MAXIMIZED_BOTH);      // Maximiza a janela
        //this.setExtendedState(WIDTH);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        botaoAdminCinemas = new javax.swing.JButton();
        botaoAdminBancos = new javax.swing.JButton();
        botaoAdminEventos = new javax.swing.JButton();
        cogumelo1 = new javax.swing.JLabel();
        cogumelo2 = new javax.swing.JLabel();
        cogumelo3 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        botaoAdminCinemas.setText("Administrar cinemas");
        botaoAdminCinemas.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                botaoAdminCinemasMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                botaoAdminCinemasMouseEntered(evt);
            }
        });
        botaoAdminCinemas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoAdminCinemasActionPerformed(evt);
            }
        });

        botaoAdminBancos.setText("Administrar bancos");
        botaoAdminBancos.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                botaoAdminBancosMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                botaoAdminBancosMouseEntered(evt);
            }
        });
        botaoAdminBancos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoAdminBancosActionPerformed(evt);
            }
        });

        botaoAdminEventos.setText("Administrar eventos");
        botaoAdminEventos.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseExited(java.awt.event.MouseEvent evt) {
                botaoAdminEventosMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                botaoAdminEventosMouseEntered(evt);
            }
        });
        botaoAdminEventos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoAdminEventosActionPerformed(evt);
            }
        });

        cogumelo1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        cogumelo3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/IMAGES/cogumelo-mario.png"))); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(98, 98, 98)
                        .addComponent(cogumelo1))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(cogumelo2, javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(cogumelo3, javax.swing.GroupLayout.Alignment.TRAILING))))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(botaoAdminCinemas)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                        .addComponent(botaoAdminBancos, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(botaoAdminEventos, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addContainerGap(141, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(45, 45, 45)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(botaoAdminCinemas)
                    .addComponent(cogumelo1))
                .addGap(52, 52, 52)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(botaoAdminBancos)
                    .addComponent(cogumelo2))
                .addGap(52, 52, 52)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(botaoAdminEventos)
                    .addComponent(cogumelo3))
                .addContainerGap(61, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botaoAdminBancosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoAdminBancosActionPerformed
        formBanco form = new formBanco(this.user, this.password);
        
        dispose();
        form.setVisible(true); 
    }//GEN-LAST:event_botaoAdminBancosActionPerformed

    private void botaoAdminCinemasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoAdminCinemasActionPerformed
        formCinema form = new formCinema(this.user, this.password);
        
        dispose();
        form.setVisible(true);
    }//GEN-LAST:event_botaoAdminCinemasActionPerformed

    private void botaoAdminEventosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoAdminEventosActionPerformed
        formEvento form = new formEvento(this.user, this.password);
        
        dispose();
        form.setVisible(true);
    }//GEN-LAST:event_botaoAdminEventosActionPerformed

    private void botaoAdminCinemasMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botaoAdminCinemasMouseEntered
        // TODO add your handling code here:
        cogumelo1.setVisible(true);
    }//GEN-LAST:event_botaoAdminCinemasMouseEntered

    private void botaoAdminCinemasMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botaoAdminCinemasMouseExited
        // TODO add your handling code here:
        cogumelo1.setVisible(false);
    }//GEN-LAST:event_botaoAdminCinemasMouseExited

    private void botaoAdminBancosMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botaoAdminBancosMouseEntered
        // TODO add your handling code here:
        cogumelo2.setVisible(true);
        
    }//GEN-LAST:event_botaoAdminBancosMouseEntered

    private void botaoAdminBancosMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botaoAdminBancosMouseExited
        // TODO add your handling code here:
        cogumelo2.setVisible(false);
    }//GEN-LAST:event_botaoAdminBancosMouseExited

    private void botaoAdminEventosMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botaoAdminEventosMouseEntered
        // TODO add your handling code here:
        cogumelo3.setVisible(true);
    }//GEN-LAST:event_botaoAdminEventosMouseEntered

    private void botaoAdminEventosMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botaoAdminEventosMouseExited
        // TODO add your handling code here:
        cogumelo3.setVisible(false);
    }//GEN-LAST:event_botaoAdminEventosMouseExited

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                //new formAdminUser().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botaoAdminBancos;
    private javax.swing.JButton botaoAdminCinemas;
    private javax.swing.JButton botaoAdminEventos;
    private javax.swing.JLabel cogumelo1;
    private javax.swing.JLabel cogumelo2;
    private javax.swing.JLabel cogumelo3;
    // End of variables declaration//GEN-END:variables
}
